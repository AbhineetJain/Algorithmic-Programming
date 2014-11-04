#include<stdio.h>

void reverse(int i, int arr[], int size);
void print(int arr[], int size);

int main()
{
	int arr[1000], size;
	int tc, i, j, val;
	scanf("%d", &tc);
	for(i=0; i<tc; i++)
	{
		scanf("%d", &size);
		for(j=0; j<size; j++)
			scanf("%d", &arr[j]);
		val=size;
		for(j=size-1; j>0; j--)
		{
			if(arr[j]>arr[j-1])
			{	
				val=j-1;
				break;
			}
		}
		for(j=size-1; j>val; j--)
		{
			if(arr[j]>arr[val])
			{
				arr[j]=arr[val]+arr[j]-(arr[val]=arr[j]);
				break;
			}
		}
		reverse(val, arr, size);
		print(arr, size);
	}
	return 0;
}

void reverse(int i, int arr[], int size)
{
	int j, k;
	for(j=i+1, k=size-1; j<k; j++, k--)
		arr[j]=arr[k]+arr[j]-(arr[k]=arr[j]);
}

void print(int arr[], int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d%s", arr[i], (i==size-1)?"\n":" ");
}
