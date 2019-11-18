/*************************************************************************
	> File Name: F.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 15时36分22秒
 ************************************************************************/

#include<stdio.h>
#define max_n 100000

long long arr[max_n + 5] = {0};

long long binary_search(long long *arr, long long p, long long n){
    long long l = 0, r = n - 1, mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if(arr[mid] == p) return 1;
        if(arr[mid] < p) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}


long long main(){
    long long n, k, s;
    scanf("%lld", &n);
    for(long long i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
    }
    scanf("%lld%lld", &k, &s);
    long long p = s - k;
    if(binary_search(arr, p, n)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
