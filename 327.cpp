/*************************************************************************
	> File Name: 327.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月24日 星期日 14时16分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 200000
#define max_m 100000

struct UnioSet{
    int fa[max_n + 5], val[max_n + 5];
    void init(int n){
        for(int i = 0; i < n; i++){
            fa[i] = i;
            val[i] = 0;
        }
    }
    int get(int x){
        if(x == fa[x]) return 0;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 2;
        return fa[x] = root;
    }
    bool merge(int a, int b){
        int aa = fa[a] , bb = fa[b];
        if(aa == bb) {
            if((val[a] + val[b]) % 2 == 0) return false;
            return true;
        }
        fa[aa] = bb;
        val[aa] = (3 + val[b] - val[b]) % 2; 
    }
};

UnioSet u;

struct Data{
    int i, j, c;
}arr[max_m + 5];

int main(){
    int n, m;
    cin >> n >> m;
    u.init(n);
    for(int i = 0; i < m; i++){
        cin >> arr[i].i >> arr[i].j >> arr[i].c;
    }
    sort(arr, arr + m, [](const Data &a, const Data &b){
        return a.c > b.c;
    });
    int ans = 0;
    for(int i = 0; i < m; i++){
        if(!u.merge(arr[i].i, arr[i].j)){
            ans = arr[i].c;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
