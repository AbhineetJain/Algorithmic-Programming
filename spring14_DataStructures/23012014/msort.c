#include<stdio.h>
//#include<stdlib.h>

long long int msort(long long int a[], long long int temp[], long long int begin, long long int end);
long long int merge(long long int a[], long long int temp[], long long int begin, long long int mid, long long int end);
/*void print(long long int a[], int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%lld ", a[i]);
	printf("\n");
}*/


int main()
{
	long long int array[100000], temp[100000];
	long long int size, j, count;
	scanf("%lld", &size);
	for(j=0; j<size; j++)
		scanf("%lld", &array[j]);
	count=msort(array, temp, 0, size-1);
	printf("%d\n", count);
	return 0;
}

long long msort(long long int a[], long long int temp[], long long int begin, long long int end)
{
	long long int mid=(begin+end)/2;
	long long int count;
	static long long int total=0;
	if(begin<end)
	{
		msort(a, temp, begin, mid);
		msort(a, temp, mid+1, end);
		count=merge(a, temp, begin, mid, end);
		total+=count;
		return total;
	}
	else
		return total;
}

long long merge(long long int a[], long long int temp[], long long int begin, long long int mid, long long int end)
{
	long long int i=begin, j=mid+1, l=0, count=0;
	while(i<=mid || j<=end)
	{
		if(a[i]>a[j]){
			temp[l++]=a[j++];
			count+=(mid-i+1);
		}
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
	return count;
}
