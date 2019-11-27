/*************************************************************************
	> File Name: 457.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月25日 星期一 13时28分43秒
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
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        s.insert(a);
    }
    int cnt = 0;
    set<int>::iterator it;
    for(it = s.begin(); it != s.end(); it++){
        arr[cnt] = *it;
        cnt += 1;
    }
    for(int i = 0; i < cnt; i++){
        if(arr[i + 1] - arr[i] > 1){
            printf("Not jolly\n");
            return 0;
        }
    }
    printf("Jolly\n");
    return 0;
}
