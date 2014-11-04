#include "heap.h"

int i=1, size;
void insertheap(int *, int);
void printheap(int *);
void shuffleup(int *);
int deletemin(int *);
void shuffledown(int *);

void insertheap(int *arr, int ip)
{
	arr[i] = ip;
	shuffleup(arr);
	i++;
}

void shuffleup(int *arr)
{
	int j=i;
	while(arr[j]<arr[j/2]){
		arr[j] = arr[j] + arr[j/2] - (arr[j/2] = arr[j]);
		j/=2;
	}
}


int deletemin(int *arr)
{
	int temp = arr[1];
	arr[1] = arr[size];
	size--;
	shuffledown(arr);
	return temp;
}

void shuffledown(int *arr)
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
