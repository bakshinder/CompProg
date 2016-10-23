#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m,q,op,r,c,no;
	scanf("%d %d %d",&n,&m,&q);
	int arr[100000],brr[100000],crr[100000];
	int drr[100][100]={0};
	for (int i = 0; i < q; i++)
	{
		scanf("%d",&op);crr[i]=op;
		if(op==3)
		{
			scanf("%d %d %d",&r,&c,&no);
			arr[i]=100*(r-1)+(c-1);
			brr[i]=no;
		}
		else
		{
			scanf("%d",&r);
			arr[i]=(r-1);
		}
	}
	int temp=0;
	for(int i=q-1;i>=0;i--)
	{
		if(crr[i]==3)
			drr[arr[i]/100][arr[i]%100]=brr[i];
		else if(crr[i]==2)
		{
			temp=drr[n-1][arr[i]];
			for(int j=n-1;j>=1;j--)
			{
				drr[j][arr[i]]=drr[j-1][arr[i]];
			}
			drr[0][arr[i]]=temp;
		}
		else
		{
			temp=drr[arr[i]][m-1];
			for(int j=m-1;j>=1;j--)
			{
				drr[arr[i]][j]=drr[arr[i]][j-1];
			}
			drr[arr[i]][0]=temp;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			printf("%d ",drr[i][j]);
		printf("\n");;
	}
	return 0;
}