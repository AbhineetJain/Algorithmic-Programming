#include<stdio.h>
#include<stdlib.h>

#define V 1
#define NV 0
#define IS 2

struct node {
	int b;
	struct node *next;
};
typedef struct node node;

node *s = NULL;

int **adMat=NULL;
int **adMatTrans=NULL;
int *state=NULL;
int *parent=NULL;
int *discovery=NULL;
int *finish=NULL;

int timer=1;

void print2D(int **mat, int size);
void dfs(int **adMat, int noVertices, int source, int ifPush);
void printArray(int *array, int size);

void push(node *, int);
int pop(node *);
void print(node *);

int allStates(int noVertices)
{
	int i, result=1;
	for (i = 0; i < noVertices; ++i)
	{
		result&=state[i];
		if(result == 0)
			return result;
	}
	return result;
}

int retFinishMax(int noVertices)
{
	int i, max=0, index = 0;
	for(i=0; i<noVertices; i++)
	{
		if(finish[i]>max && state[i] == NV) {
			max = finish[i];
			index = i;
		}
	}
	return index;
}

int main()
{
	int testCases;
	scanf("%d", &testCases);
	int k;
	int i, j, noVertices, noEdges;
	int source, dest;
	s = (node *)malloc(sizeof(node));
	int noScc=0, v;
	for(k=0; k<testCases; k++)
	{

		scanf("%d%d", &noVertices, &noEdges);
		//	printf("%d %d\n", noVertices, noEdges);
		s->next = NULL;
		s->b = 1;
		adMat = (int **)malloc(sizeof(int *)*noVertices);
		adMatTrans = (int **)malloc(sizeof(int *)*noVertices);
		discovery = (int *)malloc(sizeof(int)*noVertices);
		state = (int *)malloc(sizeof(int)*noVertices);
		finish = (int *)malloc(sizeof(int)*noVertices);
		parent = (int *)malloc(sizeof(int)*noVertices);
		noScc = 0;
		timer = 1;
		for(i=0; i<noVertices; i++)
		{
			adMat[i] = (int *)malloc(sizeof(int)*noVertices);
			adMatTrans[i] = (int *)malloc(sizeof(int)*noVertices);
			for(j=0; j<noVertices; j++)
			{
				adMat[i][j]=0;
				adMatTrans[i][j]=0;
			}
		}
		for(i=0; i<noEdges; i++){
			//		printf("%d\n", i);
			scanf("%d%d", &source, &dest);
			adMat[source][dest] = 1;
			adMatTrans[dest][source] = 1;
			//		print2D(adMat, noVertices);
			//		print2D(adMatTrans, noVertices);
		}/*
		    for(i=0; i<noVertices; i++)
		    {
		    for(j=0; j<noVertices; j++)
		    {
		    scanf("%d", &adMat[i][j]);
		    adMatTrans[j][i] = adMat[i][j];
		    }
		    }*/
		for(i=0; i<noVertices; i++)
		{
			parent[i]=-1;
			state[i]=NV;
			discovery[i]=0;
			finish[i]=0;
		}
		//	print2D(adMat, noVertices);
		//	print2D(adMatTrans, noVertices);
		for(i=0; i<noVertices; i++)
		{
			if(state[i] == NV)
			{
				//push(s, i);
				state[i]=IS;
				discovery[i] = timer++;
				dfs(adMat, noVertices, i, 1);
			}
		}
		//	printArray(discovery, noVertices);
		//	printArray(parent, noVertices);
		//	printArray(finish, noVertices);
		//	printArray(state, noVertices);
		for(i=0; i<noVertices; i++)
			state[i]=NV;
		while(allStates(noVertices)!=V)
		{
//			v = retFinishMax(noVertices);
			v = pop(s);
			while(state[v]!=NV)
				v = pop(s);	
			state[v] = IS;
			dfs(adMatTrans, noVertices, v, 0);
			noScc++;
		}
		printf("%d\n", noScc);
		for(i=0; i<noVertices; i++)
		{
			free(adMat[i]);
			free(adMatTrans[i]);
		}
		while(s->next!=NULL)
			pop(s);
		adMat = NULL;
		adMatTrans = NULL;
		free(discovery);
		free(state);
		free(parent);
		free(finish);
	}
	return 0;
}

void printArray(int *array, int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void print2D(int **mat, int size)
{
	int i, j;
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

void dfs(int **adMat, int noVertices, int source, int ifPush)
{
	int i;
	for (i = 0; i < noVertices; ++i)
	{
		if(adMat[source][i] == 1 && state[i]==NV)
		{
			state[i]=IS;
			discovery[i] = timer++;
			parent[i] = source;
			dfs(adMat, noVertices, i, ifPush);
		}
	}
	state[source] = V;
	if(ifPush)
		push(s, source);
	finish[source] = timer++;
}


void push(node *s, int ch)
{
	node *add=NULL;
	add=(node*)malloc(sizeof(node));
	if (add == NULL)
		printf("Insufficient Memory!\n");
	else 
	{
		node *temp = s->next;
		s->next=add;
		add->next=temp;
		add->b=ch;
	}
}

int pop(node *s)
{
	node *del=NULL;
	int ch;
	if (s->next == NULL)
		printf("Stack is empty!\n");
	else
	{
		del=s->next;
		s->next=del->next;
		ch=del->b;
		free(del);
	}
	return ch;
}

void print(node *s)
{
	node *temp=NULL;
	temp=s->next;
	if(temp == NULL) printf("Stack is empty!");
	while(temp!=NULL)
	{
		printf("%d ", temp->b);
		temp=temp->next;
	}
	printf("\n");
}
