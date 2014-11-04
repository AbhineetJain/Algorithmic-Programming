#include<stdio.h>

int main()
{
	int T, N;
	int i,j,value,k;
	long long int array[500];
	scanf("%d", &T);
	for(i=0; i<T; ++i)
	{
		scanf("%d", &N);
		for(j=0; j<N; j++)
			scanf("%lld", &array[j]);
		for(j=1; j<N; j++)
		{
			value=array[j];
			k=j-1;
			while(array[k]>value && k>=0)
			{
				array[k+1]=array[k];
				k--;
			}
			array[k+1]=value;
		}
		for(j=0; j<N; j++)
		{
			printf("%lld", array[j]);
			if(j!=N-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
