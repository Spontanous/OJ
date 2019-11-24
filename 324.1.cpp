/*************************************************************************
	> File Name: 324.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月24日 星期日 15时25分24秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 500000

struct UnionSet {
    int fa[max_n + 5];
    void init(int n){
        for(int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int n){
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b){
        int aa = fa[a], bb = fa[b];
        if(aa == bb) return ;
        
    }
};


UnionSet u;

int main(){
    int n, a, b;
    scanf("%d", &n);
    char *op;
    for(int i = 0; i < n; i++){
        scanf("%s%d%d", op, &a, &b);
        switch (op[0]){
            case "M" : u.merge(a, b); break;
            case "C" : {
                if(u.get(a) - u.get(c)){
                    printf("%d\n", -1);
                }else{
                    printf("%d\n", max(0. abs(u.val[a] - u.val[b] - 1)));
                }

            }break;
        }
    }
    return 0;
}
