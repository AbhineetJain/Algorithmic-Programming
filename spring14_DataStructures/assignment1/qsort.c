#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int size;
	scanf("%d", &size);
	int i, array[200005];
	for(i=0; i<size; i++)
		scanf("%d", &array[i]);
	qsort(array, size, sizeof(int), cmp);
	for(i=0; i<size; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}
