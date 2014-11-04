#include<stdio.h>

int main()
{
	unsigned long long int N;
	int n, i=0;
	scanf("%d", &n);
	while(i<n)
	{
		scanf("%llu", &N);
		int count=0;
		while(N>0)
		{
		 if(N%10==3)
		 {	
		  count++;
		 }
		 N=N/10;
		}
		printf("%d\n", count);
		i++;
	}
	return 0;
}

