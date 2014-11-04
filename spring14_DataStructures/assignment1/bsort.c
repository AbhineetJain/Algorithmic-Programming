#include<stdio.h>

int main()
{
	int T, N;
	int i,j,temp;
	long long int array[200005];
	scanf("%d", &N);
	for(j=0; j<N; j++)
		scanf("%lld", &array[j]);
	for(j=0; j<N-1; j++)
	{
		for(i=0; i<N-j-1; i++)
		{
			if(array[i]>array[i+1])
				array[i]=array[i]+array[i+1]-(array[i+1]=array[i]);
		}
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
