#include<stdio.h>

int main()
{
	int T, N;
	int i,j,small,pos;
	long long int array[200005];
	scanf("%d", &N);
	for(j=0; j<N; j++)
		scanf("%lld", &array[j]);
	for(j=0; j<N-1; j++)
	{
		small=array[j];
		pos=j;
		for(i=j+1; i<N; i++)
		{
			if(array[i]<small)
			{
				small=array[i];
				pos=i;
			}
		}
		array[j]=array[pos]+array[j]-(array[pos]=array[j]);
	}
	for(j=0; j<N; j++)
	{
		printf("%lld", array[j]);
		if(j!=N-1)
			printf(" ");
	}
	printf("\n");
	return 0;
}
