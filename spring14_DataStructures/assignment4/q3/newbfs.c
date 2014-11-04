#include<stdio.h>
#include<stdlib.h>

#define VISITED 2
#define NOT_VISITED 0
#define IN_PROGRESS 1

struct node {
	int value;
	struct node *next;
};
typedef struct node node;

int **adMat=NULL;
//int *distance=NULL;
//int *parent=NULL;
int *state=NULL;

int max=0;
int count=0;

node *qf=NULL;
node *qr=NULL;

void bfs(int **, int, int);
int findSource(int *, int);
void printMat(int **, int);
//void printArr(int *, int);

void enq(int input);
int deq();

int main()
{
	int k, noVertices, i, j, source;
	int testCases;
	scanf("%d", &testCases);
	for(k=0; k<testCases; k++)
	{
		scanf("%d", &noVertices);
		qf = qr = NULL;
		qf = (node *)malloc(sizeof(node));
		qf->next = NULL;
		qf->value = -1;
		qr = (node *)malloc(sizeof(node));
		qr->next = NULL;
		qr->value = -1;
		state = NULL;
		adMat = NULL;
		max = 0;
		count = 0;
		//	distance = (int *)malloc(sizeof(int)*noVertices);
		state = (int *)malloc(sizeof(int)*noVertices);
		//	parent = (int *)malloc(sizeof(int)*noVertices);
		adMat = (int **)malloc(sizeof(int *)*noVertices);
		for(i=0; i<noVertices; i++)
		{
			adMat[i] = (int *)malloc(sizeof(int)*noVertices);
			state[i] = NOT_VISITED;
		}
		for(i=0; i<noVertices; i++)
		{
			for(j=0; j<noVertices; j++)
				scanf("%d", &adMat[i][j]);
		}
		//	printMat(adMat, noVertices);
		source=0;
		while(source!=-1)
		{
			bfs(adMat, noVertices, source);
			//		printArr(distance, noVertices);
			//		printArr(parent, noVertices);
			//		printArr(state, noVertices);
			source=findSource(state, noVertices);
		}
		//	printf("Maximum Size of a Connected Subgraph: %d\n", max);
		printf("%d\n", max);
	}
	return 0;
}

void printMat(int **mat, int size)
{
	int i, j;
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

/*void printArr(int *arr, int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d(%d) ", i, arr[i]);
	printf("\n");
}*/

int findSource(int *state, int noVertices)
{
	int i;
	for(i=0; i<noVertices; i++)
	{
		if(state[i] == NOT_VISITED)
			return i;
	}
	return -1;
}

void bfs(int **adMat, int noVertices, int source)
{
	int i, j, k, v;
	/*for(i=0; i<noVertices; i++)
	{
		parent[i]=-1;
		distance[i]=100000;
	}*/
	//distance[source] = 0;
	state[source] = IN_PROGRESS;
	enq(source);
	count=0;
	while(qf->next!=NULL)
	{
		v = deq();
		for(i=0; i<noVertices; i++)
		{
			if(adMat[v][i]==1)
			{
				if(state[i] == NOT_VISITED)
				{
					state[i] = IN_PROGRESS;
		//			parent[i] = v;
		//			distance[i] = distance[v] + 1;
					enq(i);
				}
			}
		}
		state[v] = VISITED;
		count++;
	}
	if(count>max) max=count;
	return;	
}

void enq(int input)
{
	node *new=NULL;
	new = (node *)malloc(sizeof(node));
	if(new == NULL) printf("Memory not available\n");
	else
	{
		new->value=input;
		new->next=NULL;
		node *temp=qr->next;
		if(temp!=NULL) temp->next=new;
		qr->next=new;
		if(qf->next == NULL)
			qf->next=new;

	}
}

int deq()
{
	node *del=NULL;
	if(qf->next == NULL) printf("Queue is empty!\n");
	else
	{
		del=qf->next;
		qf->next=del->next;
		return del->value;
	}
	return -1;
}
