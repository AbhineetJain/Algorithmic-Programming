#include<stdio.h>
#include<stdlib.h>

void insert(int, int);
int collisions(int, int, int);
void search(int, int);
void print(int);

int *array = NULL;
int collision = 0;

int main()
{
	int size, i, ip;
	array = (int *)malloc(sizeof(int)*5);
	scanf("%d", &size);
	for(i=0; i<5; i++)
		array[i] = -1;
	for(i=0; i<size; i++)
	{
		scanf("%d", &ip);
		insert(ip, 5);
		printf("Total Collisions: %d\n", collision);
		print(5);
	}
	for(i=0; i<5; i++)
	{
		scanf("%d", &ip);
		search(ip, size);
	}
	return 0;
}

void insert(int ip, int size)
{
	int coll = collisions(ip, size, 0);
	if(coll == -1){
		printf("Cannot be inserted!\n");
		return;
	}
	int index = (ip + (coll*coll))%size;
	printf("Index: %d\n", index);
	printf("Collisions in this step: %d\n", coll);
	array[index] = ip;
}

int collisions(int ip, int size, int mode)
{
	int i=0;
	int val;
	if(mode == 0) val = -1;
	else val = ip; 
	while(array[(ip + (i*i))%size] != val){
		if(i>1000)
			break;
		i++;
	}
	collision += i;
	if(i>1000)
		return -1;
	return i;
}

void search(int val, int size)
{
	int coll = collisions(val, size, 1);	
	if (coll != -1)
		printf("Element %.2d found at index: %d\n", val, (val + (coll*coll))%size);
	else
		printf("Element %.2d not found\n", val);
}


void print(int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d ", array[i]);
	printf("\n");
}
