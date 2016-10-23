#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,d,a,b,mx,mn;
	string c;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>c;
		mx=200;mn=0;
		if(c=="NON_INDIAN")
		{
			mx=400;
		}
		for (int j = 0; j < a; ++j)
		{
			cin>>c;
			if(c=="CONTEST_WON")
			{
				scanf("%d",&b);
				mn+=300+max(0,20-b);
			}
			else if(c=="BUG_FOUND")
			{
				scanf("%d",&b);
				mn+=b;
			}
			else if(c=="TOP_CONTRIBUTOR")
			{
				mn+=300;
			}
			else
			{
				mn+=50;
			}
		}
		printf("%d\n", (mn/mx));
	}
	return 0;
}