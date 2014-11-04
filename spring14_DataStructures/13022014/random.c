#include<stdio.h>
#include<stdlib.h>

int main()
{
	int size;
	scanf("%d", &size);
	printf("%d\n", size);
	int i;
	for(i=0; i<size; i++)
		printf("%d ", rand()%100);
	printf("\n");
	return 0;
}
