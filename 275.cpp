/*************************************************************************
	> File Name: 275.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月25日 星期一 20时34分24秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define max_n 100
char arr[max_n + 5];
int p = 131;

int Hash(int n, char *arr){
    return Hash(n - 1, arr) * 131 + (arr[n] - 'a' + 1);
}

int insert(int a, int b, int c, int d, char *arr){
    int f1 = Hash(b, arr) - Hash(a - 1, arr) * pow(p, b - a + 1);
    int f2 = Hash(d, arr) - Hash(c - 1, arr) * pow(p, d - c + 1);
    if(f1 == f2) return 1;
    return 0;
}

int main(){
    
    int m, a, b, c, d;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c >> d;
        if(insert(a, b, c, d, arr)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
