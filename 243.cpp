/*************************************************************************
	> File Name: 243.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月10日 星期日 11时18分14秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 200000


struct range{
    long long l, r, d;
    long long cnt;
}arr[max_n + 5];

long long check(long long pos, int n){
    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i].l > pos) continue;
        if(arr[i].r <= pos) sum += arr[i].cnt;
        else sum += (pos - arr[i].l) / arr[i].d + 1;
    }
    return sum;
}


long long binary_serach(long long l, long long r, int n){
    if(l == r) return l;
    long long mid = (l + r) >> 1;
    if(check(mid, n) % 2) r = mid;
    else l = mid + 1;
    return binary_serach(l, r, n);
}


void solve(){
    int n;
    long long l, r;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld%lld%lld", &arr[i].l, &arr[i].r, &arr[i].d);
        arr[i].cnt = (arr[i].r - arr[i].l) / arr[i].d + 1;
        if(i == 0) l = arr[i].l, r = arr[i].r;
        l = min(l, arr[i].l);
        r = max(r, arr[i].r);
    }
    long long pos = binary_serach(l, r + 1, n);
    if(pos > r){
        printf("Poor QIN Teng:(\n");
    }else{
        printf("%lld %lld\n", pos, check(pos, n) - check(pos - 1, n));
    }
    return ;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
