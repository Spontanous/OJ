/*************************************************************************
	> File Name: D.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 14时33分26秒
 ************************************************************************/

#include<stdio.h>
#define max_n 8000000

int prime[max_n + 5] = {0};

int is_prime[max_n + 5] = {0};

int arr[max_n + 5] = {0};

void init(){
    for(int i = 2; i < max_n; i++){
        if(!is_prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++){
            if(prime[j] * i > max_n) break;
            is_prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int main(){
    init();
    int l, r;
    int cnt = 0;
    scanf("%d%d", &l, &r);
    for(int i = l; i <= r; i++){
       if(is_prime[i]){
        continue;
       }else{
           arr[cnt] = i;
           cnt += 1;
       }
    }
    if(cnt < 2){
        printf("There are no adjacent primes.\n");
    }else{
        int tmp = 8000000;
    int sum = 0;
    int p, h;
    for(int j = 1; j < cnt; j++){
        int k = arr[j] - arr[j - 1];
        if(k < tmp){
            tmp = k;
            h = j;
        }
        if(k > sum){
            sum = k;
            p = j;
        }
    }
    printf("%d,%d are closest, ", arr[h - 1], arr[h]);
    printf("%d,%d are most distant.\n", arr[p - 1], arr[p]);
    }
    return 0;
}

