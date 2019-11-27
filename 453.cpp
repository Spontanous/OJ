/*************************************************************************
	> File Name: 453.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月25日 星期一 12时59分43秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    set<int> s;
    int n, k, a;
    int cnt = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a;
        s.insert(a);
    }
    set<int>::iterator it;
    for(it = s.begin(); it != s.end(); it++){
        cnt += 1;
        if(cnt == k){
            printf("%d\n", *it);
        }
    }
    return 0;
}
