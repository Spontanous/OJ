/*************************************************************************
	> File Name: 372.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月15日 星期二 20时25分33秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 500000


int a[max_n + 5], b[max_n + 5];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], cin >> b[i];
    int p = 1, top1 = 0, top2 = 0;
    while (p < n){
        while(top1 != -1 && a[p] <= a[top1]) --top1;
        while(top1 != -1 && b[p] <= b[top2]) --top2;
        if(top1 -top2) break;
        a[++top1] = a[p];
        b[++top2] = b[p];
        p++;
    }
    cout << p << endl;
    return 0;
}
