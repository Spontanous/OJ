/*************************************************************************
	> File Name: 71.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月23日 星期六 16时02分53秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define max_n 10000


struct UnionSet{
    int fa[max_n + 5];
    void init(int n){
        for(int i = 1; i <= n ; i++) fa[i] = i; 
    }
    int get(int x){
        return (fa[x] = (x - fa[x] ? get(fa[x]) : x));
    }
    void merge(int a, int b){
        fa[get(a)] = get(b);
    }
};

UnionSet u;

int main(){
    int n, m;
    cin >> n >> m;
    u.init(n);
    for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    switch(a){
        case 1: u.merge(b, c); break;
        case 2: cout << (u.get(b) == u.get(c) ? "Yes" : "No") << endl; break;
    }
    }
    return 0;
}
