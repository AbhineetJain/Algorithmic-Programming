#include<stdio.h>
#include<stdlib.h>

#define NV 0
#define V 1
#define IS 2

struct vertex {
	int v;
	int wt;
};
typedef struct vertex vertex;

struct listNode {
	vertex *v;
	int freq;
	struct listNode *next;
};
typedef struct listNode node;

node **adList = NULL;

int exists = 0;
int *state = NULL;

vertex *heap = NULL;
int heapSize = 1;
vertex *heapMin = NULL;

int count=0;
int prevWt=0;

void insertList(node **adList, int source, int dest, int weight);
void printList(node **adList, int noVertices);

void dfs(node **adList, int noVertices, int source);

void insertHeap(vertex *heap, vertex *v);
void shuffleup(vertex *heap);
void deleteMin(vertex *heap);
void shuffledown(vertex *heap);

void printHeap(vertex *heap)
{
	int i;
	for(i=1; i<heapSize; i++)
	{
		printf("%d|%d ", heap[i].v, heap[i].wt);
	}
	printf("\n");
}

int main() 
{
	int tc, i, j;
	int ipWt, ipS, ipD;
	heap = (vertex *)malloc(sizeof(vertex)*300010);
	int noVertices, noEdges;
	scanf("%d", &tc);
	for(i=0; i<tc; i++)
	{
		adList = NULL;
		exists = 0;
		prevWt = 0;
		state = NULL;
		heapMin = NULL;
		heapSize = 1;
		count = 0;
		scanf("%d%d", &noVertices, &noEdges);
		adList = (node **)malloc(sizeof(node *)*(noVertices+1));
		state = (int *)malloc(sizeof(int)*(noVertices+1));
		heapMin = (vertex *)malloc(sizeof(vertex));
		for(j=0; j<noVertices+1; j++) {
			adList[j] = (node *)malloc(sizeof(node));
			adList[j]->v = NULL;
			adList[j]->freq = 0;
			adList[j]->next = NULL;
			state[j] = NV;
		}
		for(j=0; j<noEdges; j++)
		{
			scanf("%d%d%d", &ipS, &ipD, &ipWt);
			insertList(adList, ipS, ipD, ipWt);
		}
//		printList(adList, noVertices);
		dfs(adList, noVertices, 1);
		vertex *source = (vertex *)malloc(sizeof(vertex));
//		printf("\n%d\n", exists);
		if(exists == 1)
		{
			source->v = 1;
			source->wt = 0;
			insertHeap(heap, source);
			while(heap[1].v != noVertices || count != 2)
			{
//				printHeap(heap);
				deleteMin(heap);
//				printf("Deleted: %d|%d|%d\n", heapMin->v, heapMin->wt, heapMin->freq);
				node *head = adList[heapMin->v]->next;
				while(head!=NULL)
				{
					source->v = head->v->v;
					source->wt = head->v->wt+heapMin->wt;
					head->freq+=1;
				//	node *temp = adList[head->v->v]->next;
				//	while(temp->v->v!=heapMin->v)
				//		temp=temp->next;
				//	temp->v->freq+=1;
					if(head->freq <= 3){
//						printf("Inserting %d|%d|%d\n", source->v, source->wt, source->freq);
						insertHeap(heap, source);
					}
					head = head->next;
				}
				printHeap(heap);
				if(heap[1].v == noVertices){
					count++;
					if(prevWt == heap[1].wt) count--;
					prevWt = heap[1].wt;
				}
			}
			printf("%d\n", heap[1].wt);
		}
		else
			printf("-1\n");
		for(j=0; j<noVertices+1; j++)
		{
			node *head=adList[j], *temp=NULL;
			while(head!=NULL)
			{
				temp=head;
				head=head->next;
				free(temp);
			}
			adList[j]=NULL;
		}
		free(adList);
		adList=NULL;
		free(state);
		state = NULL;
		free(heapMin);
		heapMin=NULL;
		free(source);
		source=NULL;
	}
	return 0;
}

void insertList(node **adList, int source, int dest, int weight)
{
	vertex *v1=NULL, *v2=NULL;
	v1 = (vertex *)malloc(sizeof(vertex));
	v1->v = dest;
	v1->wt = weight;
	v2 = (vertex *)malloc(sizeof(vertex));
	v2->v = source;
	v2->wt = weight;
	
	node *new1 = NULL, *new2 = NULL;
	new1 = (node *)malloc(sizeof(node));
	new1->v = v1;
	new1->freq = 0;
	new1->next = NULL;
	new2 = (node *)malloc(sizeof(node));
	new2->v = v2;
	new2->freq = 0;
	new2->next = NULL;
	
	node *head = adList[source];
	while(head->next!=NULL)
		head=head->next;
	head->next = new1;
	
	head = adList[dest];
	while(head->next!=NULL)
		head=head->next;
	head->next = new2;
}

void printList(node **adList, int noVertices)
{
	int i;
	node *head = NULL;
	for(i=1; i<noVertices+1; i++)
	{
		head=adList[i]->next;
		while(head!=NULL){
			printf("%d|%d|%d ", head->v->v, head->v->wt, head->freq);
			head=head->next;
		}
		printf("\n");
	}
}

void dfs(node **adList, int noVertices, int source)
{
	int i;
	node *head = NULL;
	head = adList[source]->next;
	while(head!=NULL)
	{
		if(state[head->v->v]==NV)
		{
			state[head->v->v]=IS;
			dfs(adList, noVertices, head->v->v);
		}
		head = head->next;
	}
	state[source] = V;
//	printf("%d ", source);
	if(source == noVertices) exists = 1;
}

void insertHeap(vertex *heap, vertex *v)
{
	heap[heapSize].v = v->v;
	heap[heapSize].wt = v->wt;
	shuffleup(heap);
	heapSize++;
}

void shuffleup(vertex *heap)
{
	int j=heapSize;
	while(j>1 && heap[j].wt<heap[j/2].wt){
		heap[j].v = heap[j].v + heap[j/2].v - (heap[j/2].v = heap[j].v);
		heap[j].wt = heap[j].wt + heap[j/2].wt - (heap[j/2].wt = heap[j].wt);
		j/=2;
//		printf("Shuffleup called\n");
	}
}

void deleteMin(vertex *heap)
{
	int tempv = heap[1].v, tempwt = heap[1].wt;
	heap[1].v = heap[heapSize-1].v;
	heap[1].wt = heap[heapSize-1].wt;
	heapSize--;
	shuffledown(heap);
	heapMin->v = tempv;
	heapMin->wt = tempwt;
}

void shuffledown(vertex *heap)
{
	int j=1;
	while((2*j<=heapSize && heap[j].wt>heap[2*j].wt) || ((2*j+1)<=heapSize && heap[j].wt>heap[2*j+1].wt))
	{
		if(2*j+1<=heapSize && heap[2*j].wt>heap[2*j+1].wt){
			heap[j].v = heap[j].v + heap[2*j+1].v - (heap[2*j+1].v = heap[j].v);
			heap[j].wt = heap[j].wt + heap[2*j+1].wt - (heap[2*j+1].wt = heap[j].wt);
			j = 2*j+1;
		}
		else{
			heap[j].v = heap[j].v + heap[2*j].v - (heap[2*j].v = heap[j].v);
			heap[j].wt = heap[j].wt + heap[2*j].wt - (heap[2*j].wt = heap[j].wt);
			j = 2*j;
		}
//		printf("Shuffledown called\n");
	}
}	
