#include<stdio.h>

int retxor(int arr[], int size, int index, int xor);

int main()
{
	int arr[100], size;
	int tc, i, j;
	scanf("%d", &tc);
	for(i=0; i<tc; i++)
	{
		scanf("%d", &size);
		for(j=0; j<size; j++)
			scanf("%d", &arr[j]);
		printf("%d\n", retxor(arr, size, 0, 0));
	}
	return 0;
}

int retxor(int arr[], int size, int index, int xor)
{
	int test1, test2;
	int xor2=xor^arr[index];
	if(index==size-1)
	{
		if(xor>xor2)
			return xor;
		else
			return xor2;
	}
	else
	{
		test1=retxor(arr, size, index+1, xor);
		test2=retxor(arr, size, index+1, xor2);
		if(test1>test2)
			return test1;
		else
			return test2;
	}
}
