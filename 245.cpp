/*************************************************************************
	> File Name: 245.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月12日 星期二 15时03分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
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
