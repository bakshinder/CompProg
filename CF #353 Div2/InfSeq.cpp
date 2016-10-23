#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,d=0,a,b,c;
	//string c;
	scanf("%d %d %d",&a,&b,&c);
	if((c!=0&&(b-a)/c>=0&&(b-a)%c==0)||(c==0&&b==a))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}