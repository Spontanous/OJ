/*************************************************************************
	> File Name: 571.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月31日 星期四 20时48分32秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[max_n + 5][max_n + 5];


struct Data{
    Data(int a int b, int c){
        x = a, y = b, cnt = c;
    }
    int cnt, x, y;
};

struct DataCompare{
    bool operator()(const Data &a, const Data &b) const{
        if (a.cnt - b.cnt) return a.x < b.x;
        
    
    }
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1 && i < j){
                s.insert(Data(i, j, 0));
            }
        }
    }

    while(s.size()){
        int x = s.begin->x;
        int y = s.begin()->y;
        int cnt = s.begin()->cnt;
        s.erase(s.begin());
        for(int i = 1; i < n; i++){
            if(arr[y][i] != 1) continue;
            if(arr[x][i]) continue;
            arr[x][i] = cnt + 1;
            arr[i][x] = cnt + 1;
            s.insert(Data(x, i, cnt + i));
        }
    }
    cout << arr[x][y] - 1 << endl;
    return 0;
}
