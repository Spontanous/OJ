/*************************************************************************
	> File Name: 471.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月16日 星期六 18时36分49秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string.h>
using namespace std;

#define max_n 200

char str_a[max_n + 5][max_n + 5];
int a[max_n + 5], b[max_n + 5], ans[max_n + 5];

int main(){
    cin >> str_a >> str_b;
    memset(ans, 0, sizeof(ans));
    int len_a = strlen(str_a);
    int len_b = strlen(str_b);
    for(int i = 0; i < len_a; i++) a[len_a - i - 1] = str_a[i] - '0';
    for(int i = 0; i < len_b; i++) b[len_a - i - 1] = str_b[i] - '0';
    for(int i = 0; i < len_a; i++){
        for(int j = 0; j < len_b; j++){
            ans[i + j] += a[i] * b[j];
            if(ans[i + j] < 10) continue;
            ans[i + j + 1] += ans[i + j] / 10;
            ans[i + j] %= 10;
        }
    }
    int len_ans = len_a + len_b;
    while(ans[len_ans] == 0) len_an--;
    for(int i = len_ans; i >= 0; i--){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}

