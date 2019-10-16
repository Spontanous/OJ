/*************************************************************************
	> File Name: 264.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月15日 星期二 20时05分18秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 100000

int h[max_n + 5];
long long l[max_n + 5], r[max_n + 5];
int s[max_n + 5], top = 0;

int main(){
    int n;
    cin >> n;
    s[0] = s[n + 1] = -1;
    for(int i = 0; i < n; i++) cin >> h[i];
    s[++top] = 0;
    for(int i = 1; i <= n; i++){
        while(h[i] <= h[s[top]]) --top;
        l[i] = s[top];
        s[++top] = i;
    }
    top = -1;
    s[++top] = n + 1;
    for(int i = n; i >= 1; --i){
        while(h[i] <= h[s[top]]) --top;
        r[i] = s[top];
        s[++top] = i;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, h[i] * (r[i] - l[i] -1));
    }
    cout << ans << endl;
    return 0;
}
