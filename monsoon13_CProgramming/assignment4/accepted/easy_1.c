#include<stdio.h>

long long int product(long long int a[], long long int i, long long int size);
void create(long long int a[], long long int size);

int main()
{
	long long int tc, i;
	scanf("%lld", &tc);
	long long int arr[1000000], files;
	long long int nq, q, pro=1;
	long long int j;
	for(i=0; i<tc; i++)
	{
		scanf("%lld", &files);
		create(arr, files);
		scanf("%lld", &nq);
		for(j=0; j<files; j++)
			pro=pro*arr[j];
		for(j=0; j<nq; j++)
		{
			scanf("%lld", &q);
			if(arr[q]==0)
				printf("%lld ", product(arr, q, files));
			else
				printf("%lld ", pro/arr[q]);
		}
		printf("\n");
	}
	return 0;
}

void create(long long int a[], long long int size)
{
	long long int i;
	for(i=0; i<size; i++)
		scanf("%lld", &a[i]);
}

long long int product(long long int a[], long long int i, long long int size)
{
	long long int j;
	long long int pro=1;
	for(j=0; j<size; j++)
	{
		if(j!=i)
			pro=pro*a[j];
	}
	return pro;
}
