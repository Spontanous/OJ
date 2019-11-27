/*************************************************************************
	> File Name: 73.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月23日 星期六 19时11分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define max_n 1000000

struct UnionSet{
    int fa[max_n + 5];
    void init(int n){
        for(int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int x){
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b){
        fa[get(a)] = get(b);
    }
};

UnionSet u;
char g[1005][1005];
int n, m;
int ind(int i, int j){
    return i * m + j + 1;
}

int main(){
   
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> g[i];
    u.init(n *m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] - 'O') continue;
            if(j - 1 >= 0 && g[i][j - 1] == 'O') u.merge(ind(i, j), ind(i, j - 1));
            if(i - 1 >= 0 && g[i - 1][j] == 'O') u.merge(ind(i, j), ind(i - 1, j));
            if(i == 0 || i == n - 1) u.merge(ind(i, j), 0);
            if(j == 0 || j == m - 1) u.merge(ind(i, j), 0);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] - 'O') continue;
            ans += (u.get(0) != u.get(ind(i, j)));
        }
    }
    cout << ans << endl;
    return 0;
}
