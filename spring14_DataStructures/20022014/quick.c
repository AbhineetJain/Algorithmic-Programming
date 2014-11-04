#include<stdio.h>
#include<stdlib.h>

void print(int *, int);
void quicksort(int *, int, int);

int main()
{
	int size, *arr;
	scanf("%d", &size);
	arr = (int *)malloc(sizeof(int)*size);
	int i, ip;
	for(i=0; i<size; i++)
	{
		scanf("%d", &ip);
		arr[i]=ip;
	}
	quicksort(arr, 0, size-1);
	print(arr, size);
	return 0;
}

void print(int *arr, int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void quicksort(int *arr, int start, int end)
{
	if(end-start <= 0) return;
	int pivot = arr[end];
	int left = start;
	int j;
	for(j=start; j<end; j++)
	{
		if(arr[j] < pivot)
		{
			arr[left] = arr[j] + arr[left] - (arr[j] = arr[left]);
			left++;
		}
	}
	arr[left] = arr[j] + arr[left] - (arr[j] = arr[left]);
	quicksort(arr, start, left-1);
	quicksort(arr, left+1, end);
}
