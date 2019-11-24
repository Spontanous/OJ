/*************************************************************************
	> File Name: 78.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月19日 星期二 15时34分05秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>

#define max_n 200

char arr[max_n + 5], brr[max_n + 5];
int num[max_n + 5];

int main(){
    int len;
    scanf("%s", arr);
    scanf("%s", brr);
    int len1 = strlen(arr);
    int len2 = strlen(brr);
    
    len1 = 

    for(int i = 1; i <= num[0]; i++){
        if(num[i] < 10) continue;
        num[i + 1] = num[i] / 10;
        num[i] = num[i] % 10;
        num[0] += (num[0] == i);
    }
    for(int i = num[0]; i > 0; i--){
        printf("%d", num[i]);
    }
    printf("\n");
    return 0;
}
