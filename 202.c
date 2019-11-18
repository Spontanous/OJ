/*************************************************************************
	> File Name: 202.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月15日 星期五 20时16分44秒
 ************************************************************************/

#include<stdio.h>
#define max_n 1000
#define swap(a, b){\
    a ^= b, b ^= a, a ^= b;\
}


int arr[max_n + 5] = {0};

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    
    
    return 0;
}
