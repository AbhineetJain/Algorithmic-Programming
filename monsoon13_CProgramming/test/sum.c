#include<stdio.h>

int main()
{
	int N, a, b;
	int array[10];
	scanf("%d", &N);
	int i=0;
	for(i=0; i<N; i++)
	{
	  scanf("%d %d", &a, &b);
	  array[i]=a+b;
	}
	int j=0;
	for(j=0; j<N; j++)
	{
	  printf("%d \n", array[j]);
	}
	return 0;
}
