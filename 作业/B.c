/*************************************************************************
	> File Name: B.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月05日 星期二 15时30分24秒
 ************************************************************************/

#include<stdio.h>

#define max_n 1000000

int arr[max_n + 5] = {0};
int brr[max_n + 5] = {0};

int binary_search(int *arr, int target, int n){
    int l = 1, r = n, mid;
        while(l <= r){
            mid = (l + r) >> 1;
            if(target == arr[mid]) return mid;
            if(target > arr[mid]) l = mid + 1;
            else r = mid - 1;
        }
    return 0;
}


int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < k; i++){
        scanf("%d", &brr[i]);
    }
    
    for(int i = 0; i < k; i++){
        printf("%d", binary_search(arr, brr[i], n));
        if(i < k - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
