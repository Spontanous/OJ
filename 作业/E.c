/*************************************************************************
	> File Name: E.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 14时35分28秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>
#include <float.h>

double func(double x, int a){
    return x * exp(x) - a;
}

double binary_serach(int a){
    double l = 0, r = 50, mid;
    if(a == 0) return 0;
    while(1){
        mid = (l + r) / 2;
        if(r - l < 0.00001) return mid;
        if(func(l, a) * func(mid, a) < 0) r = mid;
        if(func(r, a) * func(mid, a) < 0) l = mid;
    }
    return 0;
}

int main(){
    int a;
    scanf("%d", &a);
    printf("%.4lf\n", binary_serach(a));
    return 0;
}
