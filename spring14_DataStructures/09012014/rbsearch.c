#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	int *x = (int *)a;
	int *y = (int *)b;
	return *x - *y;
}

void print(int arr[], int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int bin_search(int *, int , int);

int main()
{
	int arr[1000];
	int i;
	for(i = 0; i<10; i++)
	{
		arr[i]=rand()%10;
	}
	print(arr, 10);
	qsort(arr, 10, sizeof(int), cmp);
	print(arr, 10);
	int tc;
	int val, index;
	printf("Enter no. of testcases: ");
	scanf("%d", &tc);
	for(i=0; i<tc; i++)
	{
		printf("Enter value to be searched: ");
		scanf("%d", &val);
		index = bin_search(arr, 10, val);
		if (index > -1 )
			printf("Value found at index %d\n", index);
		else
			printf("Value not found\n");
	}
	return 0;
}

int bin_search(int a[], int size, int x)
{
	int low=0;
	int high=size-1;
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==x)
			return mid;
		else if(a[mid]>x)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

