/*************************************************************************
	> File Name: D2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月10日 星期日 22时17分17秒
 ************************************************************************/
 
#include<stdio.h>
#include<stdlib.h>
int a[10010],n,temp;
long int MIN()
{
	int i;
	long  int min;
	min = 2000000000;
	for (i = 0; i<n; i++)
	{
		if (a[i]<min)
		{
			min = a[i];
			temp = i;
		}
	}
	a[temp]=2000000000;
	return min;
}
int main()
{
	int i;
	long int num=0,min1,min2;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		min1=MIN();
		min2=MIN();
		num=num+min1+min2;
		a[temp]=min1+min2;
	}
	printf("%ld\n",num);
	system("pause");
	return 0;
}
 
