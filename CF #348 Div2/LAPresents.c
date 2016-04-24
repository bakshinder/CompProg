#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n,d=0;
	scanf("%d",&n);
	d=2*(n/3);
	if(n%3!=0)
		d++;
	printf("%d\n",d);
	return 0;
}