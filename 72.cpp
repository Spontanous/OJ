/*************************************************************************
	> File Name: 72.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月24日 星期日 10时25分34秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 10000

struct unionset{
    int fa[max_n + 5], val[max_n + 5];
    void init(int n){
        for(int i = 1; i <= n; i++){
            fa[i] = i;
            val[i] = 0;
        }
    }
    int get(int x){
        if(x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = root;
    }
    void merge(int a, int b){
        int aa = fa[a], bb = fa[b];
        if(aa == bb) return ;
        fa[aa] = bb;
        val[aa] = (val[a] + 2 - val[b] + 3) % 3;
        return ;
    }
};

unionset u;

int main(){
    int n, m, a, b, c;
    cin >> n >> m;
    u.init(n);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(a == 1){
            u.merge(b, c);
        }else {
            if (u.get(b) != u.get(c)) {
                cout << "Unknown" << endl;
            } else {
                switch ((u.val[b] - u.val[c] + 3) % 3) {
                    case 0: cout << "Tie" << endl; break;
                    case 1: cout << "Loss" << endl; break;
                    case 2: cout << "Win" << endl; break;
                }
            }

        }
    }
    return 0;
}

