/*************************************************************************
	> File Name: 454.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月25日 星期一 13时10分41秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define max_n 1000
int arr[max_n + 5];


int main(){
    set<int> s;
    int n, a;
    int cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        s.insert(a);
    }
    set<int>::iterator it;
    for(it = s.begin(); it != s.end(); it++){
        arr[cnt] = *it;
        cnt += 1;
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++){
        printf("%d", arr[i]);
        if(i < cnt - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
