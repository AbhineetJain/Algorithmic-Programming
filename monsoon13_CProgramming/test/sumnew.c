#include<stdio.h>

int main()
{
	int a,b,N;
	scanf("%d", &N);
	int i=0;
	while(i<N)
	{
	  scanf("%d %d", &a, &b);
	  printf("%d\n", a+b);
	  i++;
	}
	return 0;
}
