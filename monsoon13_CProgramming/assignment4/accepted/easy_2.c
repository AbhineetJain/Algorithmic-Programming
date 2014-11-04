#include<stdio.h>

long long int contxor(long long int a[], long long int j, long long int k);
void create(long long int a[], long long int size);

int main()
{
	long long int tc, i, j, k, max, xor;
	long long int arr[100000], size;
	scanf("%lld", &tc);
	for(i=0; i<tc; i++)
	{
		scanf("%lld", &size);
		create(arr, size);
		max=arr[0];
		for(j=0; j<size; j++)
		{
			for(k=j+1; k<size; k++)
			{
				xor=contxor(arr, j, k);
				if(xor>max)
					max=xor;
			}
			if(arr[j]>max)
				max=arr[j];
		}
		printf("%lld\n", max);
	}
	return 0;
}

void create(long long int a[], long long int size)
{
	long long int i;
	for(i=0; i<size; i++)
		scanf("%lld", &a[i]);
}

long long int contxor(long long int a[], long long int j, long long int k)
{
	long long int xor=a[j];
	long long int i;
	for(i=j+1; i<=k; i++)
		xor=xor^a[i];
	return xor;
}
