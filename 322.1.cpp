/*************************************************************************
	> File Name: 322.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月24日 星期日 15时43分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define max_n 500000

struct UnionSet{
    int fa[max_n + 5];
    void init(int n){
        for(int i = 0; i < n; i++) fa[i] = i;
    }
    int get(int x){
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b){
        fa[a] = get(fa[b]);
    }
}

struct Data{
    int i, j, e;
}arr[max_n + 5];

void solve(){
    for(int i = 0; i < n; i++){
        cin >> arr[i].i >> arr[i].j >> arr[i].e;
        switch(arr[i].e){
            case 1: u.merge(arr[i].i, arr[i].j); break;
            case 2: {
                if(u.merge)
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    while(n--) solve();
    return 0;
}
