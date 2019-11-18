/*************************************************************************
	> File Name: 71.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月18日 星期一 20时11分33秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

#define swap(a, b){\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

typedef struct DisjointSet{
    int *father, *size;
    int n;
}DisjointSet;

DisjointSet *init(int n){
    DisjointSet *s = (DisjointSet *)malloc(sizeof(DisjointSet));
    s->n = n;
    s->size = (int *)malloc(sizeof(int) *n);
    s->father = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        s->father[i] = i;
        s->size[i] = 1;
    }
    return s;
}

int find(DisjointSet *s, int x){
    if(s->father[x] == x) return x;
    return s->father[x] = (s->father[x] == x ? x : find(s, s->father[x]));
}

int merge(DisjointSet *s, int a, int b){
    int fa = find(s, a), fb = find(s, b);
    if(s->father[fa] == s->father[fb]) return 0;
    if(s->size[fa] > s->size[fb]) swap(fa, fb);
    s->father[fa] = fb;
    s->size[fb] += s->size[fa];
    return 1;
}


void clear(DisjointSet *s){
    if(s == NULL) return ;
    free(s->father);
    free(s->size);
    free(s);
    return ;
}

int main(){
    int n, m, a, b, c;
    scanf("%d%d", &n, &m);
    DisjointSet *s = init(n + 1);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &c);
        switch(a) {
            case 1: merge(s, b, c); break;

            case 2: printf("%s\n", find(s, b) == find(s, c) ? "Yes" : "No");
        }
    }
    clear(s);
    return 0;
}
