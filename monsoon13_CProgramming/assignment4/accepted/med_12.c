#include<stdio.h>

void create(long long int a[], long long int size);

int main()
{
	long long int years, profit[100000];
	long long int start, end;
	scanf("%lld", &years);
	create(profit, years);
	scanf("%lld %lld", &start, &end);
	while(start!=-1 && end!=-1)
	{
		if(start!=1)
			printf("%lld\n",profit[end-1]-profit[start-2]);
		else
			printf("%lld\n",profit[end-1]);
		scanf("%lld %lld", &start, &end);
	}
	return 0;
}


void create(long long int a[], long long int size)
{
	int i;
	scanf("%lld", &a[0]);
	for(i=1; i<size; i++)
	{	
		scanf("%lld", &a[i]);
		a[i] = a[i-1] + a[i];
	}
}
