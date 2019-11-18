/*************************************************************************
	> File Name: C.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月05日 星期二 16时07分44秒
 ************************************************************************/

#include<stdio.h>
#define max_n 8000000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

int main(){
    for(int i = 2; i <= max_n; i++){
        if(!is_prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++){
            if(i * prime[j] > max_n) break;
            is_prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }

    int n, cnt = 0;
    scanf("%d", &n);
    for(int i = 1; i <= prime[0]; i++){
        if(prime[i] > n / 2) break;
        if(is_prime[n - prime[i]]) continue;
        cnt += 1;
    }
    printf("%d\n", cnt);
    return 0;
}
