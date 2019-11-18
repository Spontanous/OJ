/*************************************************************************
	> File Name: G.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 16时15分12秒
 ************************************************************************/

#include<stdio.h>
#define max_n 100000

long long arr[max_n + 5] = {0};

long long binary_serach(long long *arr, long long n, long long s){
    long long l = 0, r = n - 1, mid;
    for(long long i = 0; i < n; i++){
        long long k = s - arr[i];
        while(l <= r){
            mid = (l + r) >> 1;
            if(arr[mid] == k) return 1;
            if(arr[mid] < k) l = mid + 1;
            else r = mid - 1;
        }
    }
    return 0;
}


int main(){
    long long n, s;
    scanf("%lld", &n);
    for(long long i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
    }
    scanf("%lld", &s);
    if(binary_serach(arr, n, s)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
