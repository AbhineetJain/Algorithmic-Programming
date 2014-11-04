#include<stdio.h>

void msort(long long int a[], long long int temp[], int begin, int end);
void merge(long long int a[], long long int temp[], int begin, int mid, int end);
void print(long long int a[], int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%lld ", a[i]);
	printf("\n");
}

int main()
{
	int tc, i;
	long long int array[200005], temp[200005];
	int size, j;
	scanf("%d", &size);
	for(j=0; j<size; j++)
		scanf("%lld", &array[j]);
	msort(array, temp, 0, size-1);
	print(array, size);
	return 0;
}

void msort(long long int a[], long long int temp[], int begin, int end)
{
	int mid=(begin+end)/2;
	if(begin<end)
	{
		msort(a, temp, begin, mid);
		msort(a, temp, mid+1, end);
		merge(a, temp, begin, mid, end);
	}
	else
		return;
}

void merge(long long int a[], long long int temp[], int begin, int mid, int end)
{
	int i=begin, j=mid+1, l=0;
	while(i<=mid || j<=end)
	{
		if(a[i]>a[j])
			temp[l++]=a[j++];
		else
			temp[l++]=a[i++];
		if(i>mid)
		{
			while(j<=end)
				temp[l++]=a[j++];
		}
		else if(j>end)
		{
			while(i<=mid)
				temp[l++]=a[i++];
		}
	}
	for(i=begin, l=0; i<end+1; i++, l++)
		a[i]=temp[l];
}
