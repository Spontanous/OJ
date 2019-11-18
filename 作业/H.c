/*************************************************************************
	> File Name: H.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 17时26分59秒
 ************************************************************************/

#include<stdio.h>
#define max_n 100000

int arr[max_n + 5] = {0};
int brr[max_n + 5] = {0};

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &brr[i]);
    }
    
    return 0;
}
