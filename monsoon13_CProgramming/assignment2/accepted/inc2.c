#include<stdio.h>

int main()
{
	long long int array[500];
	int T, N, i, j,k, max, final, ls[500]={0};
	scanf("%d", &T);
	for(i=0; i<T; i++)
	{
		scanf("%d", &N);
		for(j=0; j<N; j++)
			scanf("%lld", &array[j]);
		ls[0]=final=1;
		for(j=1; j<N; j++)
		{
			max=1;
			for(k=0; k<j; k++)
			{
				if(array[j]>array[k])
			 	{	ls[j]=1+ls[k];}
				else
				{	ls[j]=1;}
				if(ls[j]>max)
					max=ls[j];
			}
			ls[j]=max;
			if(max>final)
				final=max;
		}
		printf("%d\n", final);
	}
	return 0;
}

