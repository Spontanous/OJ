/*************************************************************************
	> File Name: D1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月10日 星期日 21时55分53秒
 ************************************************************************/

#include<stdio.h>
#define max_n 10000
#define MAX_N 20000
int arr[max_n + 5];
int tmp;

int MIN(int n){
    int  i;
    int min;
    min = MAX_N;
    for(int i = 0; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
            tmp = i;
        }
    }
    arr[tmp] = MAX_N;
    return min;
}

int main(){
    int n;
    long long sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int i = 0; i < n -1; i++){
        int min1 = MIN(n);
        int min2 = MIN(n);
        sum = sum + min1 + min2;
        arr[tmp] = min1 + min2;
    }

    printf("%lld\n", sum);
    return 0;
}
