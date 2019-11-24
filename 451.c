/*************************************************************************
	> File Name: 451.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月24日 星期日 17时48分50秒
 ************************************************************************/

#include<stdio.h>
#define max_n 100000

int arr[max_n + 5];

void quick_sort(int l, int r, int *arr){
    if(r < l) return ;
    int x = l, y = r, z = arr[l];
    while(x < y){
        while(x < y && arr[y] >= z) y--;
        if(x < y) arr[x++] = arr[y];
        while(x < y && arr[x] <= z) x++;
        if(x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort(l, x - 1, arr);
    quick_sort(x + 1, r, arr);
    return ;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    quick_sort(0, n - 1, arr);
    for(int i = 0; i < n; i++) printf("%d\n", arr[i]);
    return 0;
}
