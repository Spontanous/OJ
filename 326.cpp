/*************************************************************************
	> File Name: 326.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月25日 星期一 16时05分53秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 100000

int arr[max_n + 5];

struct UnionSet{
    int fa[max_n + 5], val[max_n + 5];
    void init(int n){
        for(int i = 0; i < n; i++){
            fa[i] = i;
            val[i] = 1;
        }
    }
    int get(int x){
        return fa[x] = (fa[x] == x ? x : get(get(fa[x])));
    }
    int merge(int a, int b){
        fa[get(a)] = get(b);
    }
};

struct Data{
    int i, j, k;
}arr[max_n + 5];


int main(){
    int n, k;
    cin >> n >> k;
    u.init(n);
    for(int i = 0; i < k; i++){
        cin >> arr[i].i >> arr[i].j >> arr[i].k;
        if(arr[i].j > n || arr[i].k > n) cnt += 1;
        switch (arr[i].i){
            case 1: {
                if(!u.merge(arr[i].j, arr[i],k)){
                    if(!(u.val[arr[i].j] - u.val[i].k)) cnt += 1;
                }
            }break;
            case 2: {
                if(u.get(arr[i].j) == u.get(arr[i].k)) cnt += 1;
                u.merge()
            }
        }
    }
    return 0;
}
