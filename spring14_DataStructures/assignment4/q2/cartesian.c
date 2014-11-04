#include<stdio.h>
#include<stdlib.h>

int *array = NULL;
int *postOrder = NULL;
int *preOrder = NULL;
int preCounter = 0;
int postCounter = 0;

void printArr(int *, int, int);
void partition(int *, int, int);
int  findMin(int *, int, int);

int main()
{
	int testCases, i, j, size;
	scanf("%d", &testCases);
	for(i=0; i<testCases; i++)
	{
		array = NULL;
		postOrder = NULL;
		preOrder = NULL;
		preCounter = 0;
		postCounter = 0;
		scanf("%d", &size);
		array = (int *)malloc(sizeof(int)*size);
		preOrder = (int *)malloc(sizeof(int)*size);
		postOrder = (int *)malloc(sizeof(int)*size);
		for(j=0; j<size; j++)
		{
			scanf("%d", &array[j]);
		}
		partition(array, 0, size-1);
		printArr(preOrder, 0, size-1);
		printArr(postOrder, 0, size-1);
	}
	return 0;
}

void printArr(int *arr, int start, int end)
{
	int i;
	for(i=start; i<end; i++)
		printf("%d ", arr[i]);
	printf("%d\n", arr[end]);
}

void partition(int *arr, int start, int end)
{
	if(start <= end) {
		int index = findMin(arr, start, end);
		preOrder[preCounter++] = arr[index];
		partition(arr, start, index-1);
		partition(arr, index+1, end);
		postOrder[postCounter++] = arr[index];
	}
}

int findMin(int *arr, int start, int end)
{
	int i, min = arr[start], minIndex = start;
	for(i=start+1; i<=end; i++)
	{
		if(arr[i] < min){
			min = arr[i];
			minIndex = i;
		}
	}
	return minIndex;
}
