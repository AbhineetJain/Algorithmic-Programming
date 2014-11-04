#include<stdio.h>
#include<stdlib.h>

int *arr=NULL, size, i=1;
void insert(int);
void print();
void shuffleup();
int deletemin();
void shuffledown();

int main()
{
	scanf("%d", &size);
	arr = (int *)malloc(sizeof(int)*size);
	int j, ip;
	for(j=0; j<size; j++)
	{
		scanf("%d", &ip);
		insert(ip);
	}
	while(size){
		printf("%d ", deletemin());
	}
	printf("\n");
	return 0;
}

void insert(int ip)
{
	arr[i] = ip;
	shuffleup();
	i++;
}

void shuffleup()
{
	int j=i;
	while(arr[j]<arr[j/2]){
		arr[j] = arr[j] + arr[j/2] - (arr[j/2] = arr[j]);
		j/=2;
	}
}

void print()
{
	int j;
	for(j=1; j<=size; j++)
		printf("%d ", arr[j]);
	printf("\n");
}

int deletemin()
{
	int temp = arr[1];
	arr[1] = arr[size];
	size--;
	shuffledown();
	return temp;
}

void shuffledown()
{
	int j=1;
	while((2*j<=size && arr[j]>arr[2*j]) || ((2*j+1)<=size && arr[j]>arr[2*j+1]))
	{
		if(arr[2*j]>arr[2*j+1]){
			arr[j] = arr[j] + arr[2*j+1] - (arr[2*j+1] = arr[j]);
			j = 2*j+1;
		}
		else{
			arr[j] = arr[j] + arr[2*j] - (arr[2*j] = arr[j]);
			j = 2*j;
		}
	}
}	
