/*************************************************************************
	> File Name: 274.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月25日 星期一 14时25分21秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define max_n 100000

int arr[max_n + 5][6];
int val[max_n + 5];
int P = 99991, cnt = 0;
int head[max_n + 5], next1[max_n + 5];
int snow[max_n + 5][6];

int Hash(int *arr, int n){
    int sum = 0;
    long long ans = 1;
    for(int i = 0; i < n; i++){
        sum = (sum +  arr[i]) % P;
        ans = (ans * arr[i]) % P;
    }
    return (ans + sum) % P;
}


int comp(int *a, int *b){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            int ans = 1;
            for(int k = 0; k < 6; k++){
                if(a[(i + k) % 6] != b[(j + k) % 6]) ans = 0;
            }
            if(ans) return 1;
            ans = 1;
            for(int k = 0; k < 6; k++){
                if(a[(i + k) % 6] != b[(j - k + 6) % 6]) ans = 0;
            }
            if(ans) return 1;
        }
    }
    return 0;
}


int insert(int val, int *arr){
    for(int i = head[val]; i; i = next1[i]){
        if(comp(snow[i], arr)) return 0;
    }
    
    cnt += 1;
    memcpy(snow[cnt], arr, 6 * sizeof(int));
    next1[cnt] = head[val];
    head[val] = cnt;
    return 1;
}



int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            cin >> arr[i][j];
        }
        val[i] = Hash(arr[i], 6);
        if(!insert(val[i], arr[i])){
            printf("Twin snowflakes found.\n");
            return 0;
        }
    }
    printf("No two snowflakes are alike.\n");
    return 0;
}
