/*************************************************************************
	> File Name: 72.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月23日 星期六 14时42分42秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

#define swap(a, b){\
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

typedef struct unionset{
    int *father, *size;
    int n;
}unionset;


unionset *init(int n){
    unionset *u = (unionset *)malloc(sizeof(unionset));
    u->father = (int *)malloc(sizeof(int) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    u->n = n;
    for(int i = 0; i < n; i++){
        u->father[i] = i;
        u->size[i] = 1;
    }
    return u;
}

int find(unionset *u, int x){
    if(u->father[x] == x) return x;
    return u->father[x] = (u->father[x] == x ? x : find(u, u->father[x]));
}

int merge(unionset *u, int a, int b){
    int fa = find(u, a), fb = find(u, b);
    if(fa == fb) return 0;
    if(u->size[fa] > u->size[fb]) swap(fa, fb);
    u->father[fa] = fb;
    u->size[fb] += u->size[fa];
    return 1;
}

void clear(unionset *u){
    if(u == NULL) return ;
    free(u->father);
    free(u->size);
    free(u);
    return ;
}

int main(){
    int n, m, a, b, c;
    scanf("%d%d", &n, &m);
    unionset *u = init(n);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &c);
        switch(a){
            case 1:{
                merge(u, b, c) == 0; 
            }break;
            case 2:{
                if(find(u, b) == b || find(u, c) == c) printf("Unknow\n");
                else if(find(u, b) != b && find(u, b) == find(u, c)) printf("Loss\n");
                else if(find(u, c) != c && find(u, b) == find(u, c)) printf("Win\n");
                else if(find(u, b) == find(u, c)) printf("Tie\n");
            }break;
        }
    }
    return 0;
}
