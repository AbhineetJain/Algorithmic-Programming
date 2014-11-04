#include<stdio.h>
#include<stdlib.h>
#include "heap.h"

int main()
{
	int *arr=NULL;
	scanf("%d", &size);
	arr = (int *)malloc(sizeof(int)*size);
	int j, ip;
	for(j=0; j<size; j++)
	{
		scanf("%d", &ip);
		insertheap(arr, ip);
	}
	while(size){
		printf("%d ", deletemin(arr));
	}
	printf("\n");
	return 0;
}
