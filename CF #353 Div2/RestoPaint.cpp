#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	long long int n,d,a,b,c,dif1,dif2,dif3,mx,mn;
	//string c;
	scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
	dif1=c-b;
	dif2=d-a;
	dif3=(c+d)-(a+b);
	mx=max(dif1,max(dif2,dif3));
	mn=min(dif1,min(dif2,dif3));
	if(mx<0&&abs(mn)<=n)
		printf("%lld\n", (n*(n+mn)));
	else if(mn>0&&mx<=n)
		printf("%lld\n", (n*(n-mx)));
	else if(mx>=0&&mn<=0&&abs(mx-mn)<=n)
		printf("%lld\n", (n*(n+mn-mx)));
	else
		printf("0\n");
	return 0;
}