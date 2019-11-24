/*************************************************************************
	> File Name: 323.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月24日 星期日 16时15分51秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 10000

struct UnionSet{
    int fa[max_n + 5];
    void init(int n){
        for(int i = 0; i <= n; i++){
            fa[i] = i;
        }
    }
        int get(int x){
            return fa[x] = (fa[x] == x ? x : get(fa[x])); 
        }
        void merge(int a, int b){
            fa[get(a)] = get(b);
        }
};

UnionSet u;

struct Data{
    int p, d;
}arr[max_n + 5];

void solve(int n){
    for(int i = 0; i < n; i++){
        cin >> arr[i].p >> arr[i].d;
    }
    sort(arr, arr + n, [](const Data &a, const Data &b){
        return a.p > b.p;
    });
    u.init(max_n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int d = u.get(arr[i].d);
        if(d == 0) continue;
        ans += arr[i].p;
        u.merge(d, d- 1);
    }
    cout << ans << endl; 
}

int main(){
    int n;
    while(cin >> n){
        solve(n);
    } 
    return 0;
}
