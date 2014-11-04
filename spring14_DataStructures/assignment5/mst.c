#include<stdio.h>
#include<stdlib.h>

struct edge {
	int v;
	int w;
	int wt;
};
typedef struct edge edge;

edge *heap = NULL;
int heapSize = 1;
edge *heapMin = NULL;

void insertHeap(edge *, int, int, int);
void shuffleup(edge *);
void shuffledown(edge *);
void deleteMin(edge *);
void printHeap(edge *heap)
{
	int i;
	for(i=1; i<heapSize; i++)
	{
		printf("%d|%d|%d ", heap[i].v, heap[i].w, heap[i].wt);
	}
	printf("\n");
}

struct element {
	int v;
	int parent;
	struct element *next;
};
typedef struct element element;

void makeSet(int v);
void unionSet(int v, int w);
int  findSet(int v);
void printSet(int v);
int  searchList(element *start, int v);

element **sets = NULL;
int *sizes = NULL;

int noVertices, noEdges;

int main()
{
	int testCases;
	scanf("%d", &testCases);
	int i, j;
	int v, w, wt;
	heapMin = (edge *)malloc(sizeof(edge));
	for(i=0; i<testCases; i++)
	{
		scanf("%d%d", &noVertices, &noEdges);
		sets = (element **)malloc(sizeof(element *)*noVertices);
		heap = (edge *)malloc(sizeof(edge)*(50005));
		sizes = (int *)malloc(sizeof(int)*noVertices);
		for(j=0; j<noVertices; j++)
		{	
			sizes[j] = 0;
			makeSet(j);
//			printSet(j);
		}
		for(j=0; j<noEdges; j++)
		{
			scanf("%d%d%d", &v, &w, &wt);
			insertHeap(heap, v, w, wt);
//			printHeap(heap);
		}
		for(j=0; j<noVertices-1; j++)
		{
			deleteMin(heap);
			int set1 = findSet(heapMin->v);
			int set2 = findSet(heapMin->w);
			if(set1!=set2)
			{
				unionSet(set1, set2);
				printf("%d %d %d\n", heapMin->v, heapMin->w, heapMin->wt);
			}
			else
				j--;
		}
		heapSize = 1;
		free(heap);
		heap = NULL;
		free(sizes);
		sizes=NULL;
		for(j=0; j<noVertices; j++)
		{
			element *head=sets[j], *temp=NULL;
			while(head!=NULL)
			{
				temp=head;
				head=head->next;
				if(temp == NULL) printf("Fault");
				free(temp);
			}
			sets[j] = NULL;
		}
		free(sets);
		sets=NULL;
	}
	return 0;
}

void makeSet(int v)
{
	sets[v] = (element *)malloc(sizeof(element));
	sets[v]->v = v;
	sets[v]->parent = v;
	sets[v]->next = NULL;
	sizes[v] = 1;
}

int findSet(int v)
{
	int i;
	int findResult;
	for(i=0; i<noVertices; i++)
	{
		findResult = searchList(sets[i], v);
		if(findResult!=-1)
			return findResult;
	}
	return -1;
}

int searchList(element *start, int v)
{
	element *temp = NULL;
	int result;
	temp = start;
	while(temp!=NULL)
	{
		if(temp->v == v)
			return temp->parent;
		temp = temp->next;
	}
	return -1;
}

void printSet(int v)
{
	element *temp = sets[v];
	while(temp!=NULL)
	{
		printf("%d(%d) ", temp->v, temp->parent);
		temp=temp->next;
	}
	printf("\n");
}

void unionSet(int v, int w)
{
	element *temp = NULL;
	if(sizes[v] < sizes[w])
	{
		temp = sets[w];
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next = sets[v];
		temp = temp->next;
		while(temp!=NULL){
			temp->parent = w;
			temp=temp->next;
		}
		sizes[w]+=sizes[v];
		sets[v] = NULL;
		sizes[v] = 0;
	}
	else
	{
		temp = sets[v];
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next = sets[w];
		temp = temp->next;
		while(temp!=NULL){
			temp->parent = v;
			temp=temp->next;
		}
		sizes[v]+=sizes[w];
		sets[w] = NULL;
		sizes[w] = 0;
	}

}


void insertHeap(edge *heap, int v, int w, int wt)
{
	heap[heapSize].v = v;
	heap[heapSize].w = w;
	heap[heapSize].wt = wt;
	shuffleup(heap);
	heapSize++;
}

void shuffleup(edge *heap)
{
	int j=heapSize;
	while(j>1 && heap[j].wt<heap[j/2].wt){
		heap[j].v = heap[j].v + heap[j/2].v - (heap[j/2].v = heap[j].v);
		heap[j].w = heap[j].w + heap[j/2].w - (heap[j/2].w = heap[j].w);
		heap[j].wt = heap[j].wt + heap[j/2].wt - (heap[j/2].wt = heap[j].wt);
		j/=2;
//		printf("Shuffleup called\n");
	}
}

void deleteMin(edge *heap)
{
	int tempv = heap[1].v, tempw = heap[1].w, tempwt = heap[1].wt;
	heap[1].v = heap[heapSize-1].v;
	heap[1].w = heap[heapSize-1].w;
	heap[1].wt = heap[heapSize-1].wt;
	heapSize--;
	shuffledown(heap);
	heapMin->v = tempv;
	heapMin->w = tempw;
	heapMin->wt = tempwt;
}

void shuffledown(edge *heap)
{
	int j=1;
	while((2*j<=heapSize && heap[j].wt>heap[2*j].wt) || ((2*j+1)<=heapSize && heap[j].wt>heap[2*j+1].wt))
	{
		if(2*j+1<=heapSize && heap[2*j].wt>heap[2*j+1].wt){
			heap[j].v = heap[j].v + heap[2*j+1].v - (heap[2*j+1].v = heap[j].v);
			heap[j].w = heap[j].w + heap[2*j+1].w - (heap[2*j+1].w = heap[j].w);
			heap[j].wt = heap[j].wt + heap[2*j+1].wt - (heap[2*j+1].wt = heap[j].wt);
			j = 2*j+1;
		}
		else{
			heap[j].v = heap[j].v + heap[2*j].v - (heap[2*j].v = heap[j].v);
			heap[j].w = heap[j].w + heap[2*j].w - (heap[2*j].w = heap[j].w);
			heap[j].wt = heap[j].wt + heap[2*j].wt - (heap[2*j].wt = heap[j].wt);
			j = 2*j;
		}
//		printf("Shuffledown called\n");
	}
}	
