#include<stdio.h>
#include<stdlib.h>


int main()
{
	int i;
	i=101;
	printf("%d\n", __builtin_popcount(i));
	return 0;
}
