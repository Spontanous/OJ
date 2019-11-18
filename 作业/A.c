/*************************************************************************
	> File Name: A.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月05日 星期二 14时51分35秒
 ************************************************************************/

#include<stdio.h>
#define max_n 1000000

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
    int n, m;
    scanf("%d%d", &n, &m);
    
    for(int i = m; i <= n; i++){
        if(!is_prime[i]) printf("%d\n", i);
    }

    return 0;
}
