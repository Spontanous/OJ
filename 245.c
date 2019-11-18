/*************************************************************************
	> File Name: 245.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月12日 星期二 15时47分48秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#define max_n 100000

int arr[max_n + 5] = {0};

int main(){
    int n, tmp = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++){
        int l = abs(arr[0] - arr[i]);
        tmp += l;
    }
    for(int i = 1; i < n; i++){
        int ans = arr[i];
        int sum = 0;
        for(int j = 0; j < n; j++){
            int k = abs(ans - arr[j]);
            sum += k;
            if(sum > tmp){
                sum = tmp;
                continue;
            }
        }
        tmp = sum;
    }
    printf("%d\n", tmp);
    return 0;
}

