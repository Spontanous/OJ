/*************************************************************************
	> File Name: 322.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月18日 星期一 21时29分10秒
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
    int t, n, i, j, e;
    scanf("%d", &t);
    
    for(int k = 0; k < t; k++){
        DisjointSet *s = init(n);
        scanf("%d", &n);
        for(int l = 0; l < n; l++){
            scanf("%d%d%d", &i, &j, &e);
            switch(e){
                case 1: merge(s, i, j); break; 
                case 0: s->father[i] = i, s->father[j] = j;
            }
            // if(s->father[i] == s->father[j]) printf("YES\n");
            //else printf("NO\n");
        }
        clear(s);
    }
    return 0;
}
