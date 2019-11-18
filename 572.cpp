/*************************************************************************
	> File Name: 572.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月02日 星期六 14时32分43秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define Max_n 40000

long long a[Max_n + 5], b[Max_n + 5];

struct Data{
    Data(long long val, long long i, long long j) : val(val), i(i), j(j) {}
    long long val, i, j;
    bool operator<(const Data &a) const{
        if(val - a.val) return val < a.val;
        if(i - a.i) return i < a.i;
        return j < a.j;
    }
};

set<Data> s;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%lld", a + i);
    for(int i = 0 ; i < n; i++) scanf("%lld", b + i);
    s.insert(Data(a[0] + b[0], 0, 0));
    for(long long i = 0; i < n; i++){
        int val = s.begin()->val;
        int x = s.begin()->i;
        int y = s.begin()->j;
        s.erase(s.begin());
        cout << val << endl;
        if(x + 1 < n) s.insert(Data(a[x + 1] + b[y], x + 1, y));
        if(y + 1 < n) s.insert(Data(a[x] + b[y + 1], x,  y + 1));
    }
    return 0;
}
