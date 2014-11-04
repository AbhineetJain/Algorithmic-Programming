#include<stdio.h>
#include<stdlib.h>

int minheap=1, maxheap=1;
int minHeap[1000000], maxHeap[1000000];
void insertheap(int *, int, int);
void printheap(int *, int);
void shuffleup(int *, int);
int deletemin(int *, int);
void shuffledown(int *, int);

int main()
{
	int noQueries, i, op, cutoff, ipScore;
	scanf("%d", &noQueries);
	for(i=0; i<noQueries; i++)
	{
		scanf("%d", &op);
		switch(op)
		{
			case 1: if(minheap != 1)
				{
					cutoff = minHeap[1];
					printf("%d\n", cutoff);
				}
				else
					printf("-1\n");
				break;

			case 2: scanf("%d", &ipScore);
//				printf("%d %d\n", ipScore, maxheap+minheap);
				if(maxheap + minheap < 6){
					insertheap(maxHeap, -1*ipScore, 1);
//					printf("%d\n", maxHeap[1]);
				}
				else 
				{
					if(ipScore < minHeap[1])
						insertheap(maxHeap, -1*ipScore, 1);
					else
					{
						insertheap(maxHeap, -1*deletemin(minHeap, 0), 1);
						insertheap(minHeap, ipScore, 0);
					}
				}
				if((maxheap + minheap)%4 == 2)
					insertheap(minHeap, -1*deletemin(maxHeap, 1), 0);
/*				printf("MaxHeap: ");
				printheap(maxHeap, maxheap-1);
				printf("MinHeap: ");
				printheap(minHeap, minheap-1);
*/				break;
		}
	}
	return 0;
}

void insertheap(int *arr, int ip, int heap)
{
	if(heap) heap = maxheap++;
	else heap = minheap++;
	arr[heap] = ip;
//	printf("heap:%d ip:%d %d\n", heap, ip, arr[heap]);
	shuffleup(arr, heap);
//	printf("%d\n", arr[heap]);
}

void shuffleup(int *arr, int heap)
{
	int j=heap;
	while(arr[j]<arr[j/2] && j!=1){
//			printf("Enter shuffleup while\n");
			arr[j] = arr[j] + arr[j/2] - (arr[j/2] = arr[j]);
			j/=2;
	}
	
}


int deletemin(int *arr, int size)
{
	if(size)
	{
		size = maxheap-1;
		maxheap--;
	}
	else 
	{
		size = minheap-1;
		minheap--;
	}
	int temp = arr[1];
	arr[1] = arr[size];
	shuffledown(arr, size-1);
	return temp;
}

void shuffledown(int *arr, int size)
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


void printheap(int *arr, int size)
{
	int j;
	for(j=1; j<=size; j++)
		printf("%d ", arr[j]);
	printf("\n");
}
