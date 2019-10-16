/*************************************************************************
	> File Name: 271.c
	> Author: 
	> Mail: 
	> Created Time: 2019年10月15日 星期二 18时50分20秒
 ************************************************************************/

#include<stdio.h>
#define max 300000
int arr[max + 5] = {0};
int q[max + 5], head, tail;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    head = tail = 0;
    for(int i = 0; i < n; i++){
        while(tail - head && arr[i] < arr[q[tail - 1]]) tail--;
        q[tail++] = i;
        if(i+1 < k) continue;
        if(i - q[head] == k) head++;
        i + 1 == k || printf(" ");
        printf("%d", arr[q[head]]);
    }
    printf("\n");
    
    head = tail = 0;
     for(int i = 0; i < n; i++){
        while(tail - head && arr[i] > arr[q[tail - 1]]) tail--;
        q[tail++] = i;
        if(i+1 < k) continue;
        if(i - q[head] == k) head++;
        i + 1 == k || printf(" ");
        printf("%d", arr[q[head]]);
    }
    printf("\n");

   return 0;
}
