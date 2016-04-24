#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,d=0;
	string c;
	scanf("%d",&n);
	int arr[100000],brr[100000]={0};
	cin>>c;
	for (int i = 0; i < n; i++)
	{
		if(c.at(i)=='<')
			arr[i]=-1;
		else
			arr[i]=1;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&d);
		arr[i]*=d;
	}
	int pos=0;
	while(pos>=0&&pos<n)
	{
		if(brr[pos]==1)
			break;
		brr[pos]=1;
		pos+=arr[pos];
	}
	if(pos>=0&&pos<n)
		printf("INFINITE\n");
	else
		printf("FINITE\n");
	return 0;
}