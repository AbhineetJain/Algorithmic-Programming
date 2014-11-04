#include<stdio.h>
#include<stdlib.h>

#define V 1
#define NV 0
#define IS 2

int **adMat=NULL;
int **adMatTrans=NULL;
int *state=NULL;
int *parent=NULL;
int *discovery=NULL;
int *finish=NULL;

int timer=1;

void print2D(int **mat, int size);
void dfs(int **adMat, int noVertices, int source);
void printArray(int *array, int size);

int allStates(int noVertices)
{
	int i, result=1;
	for (i = 0; i < noVertices; ++i)
	{
		result&=state[i];
	}
	return result;
}

int retFinishMax(int noVertices)
{
	int i, max=finish[0], index = 0;
	for(i=1; i<noVertices; i++)
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
	int i, j, noVertices;
	scanf("%d", &noVertices);
	adMat = (int **)malloc(sizeof(int *)*noVertices);
	adMatTrans = (int **)malloc(sizeof(int *)*noVertices);
	discovery = (int *)malloc(sizeof(int)*noVertices);
	state = (int *)malloc(sizeof(int)*noVertices);
	finish = (int *)malloc(sizeof(int)*noVertices);
	parent = (int *)malloc(sizeof(int)*noVertices);
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
	for(i=0; i<noVertices; i++)
	{
		for(j=0; j<noVertices; j++)
		{
			scanf("%d", &adMat[i][j]);
			adMatTrans[j][i] = adMat[i][j];
		}
	}
	for(i=0; i<noVertices; i++)
	{
		parent[i]=-1;
		state[i]=NV;
		discovery[i]=0;
		finish[i]=0;
	}
	print2D(adMat, noVertices);
	print2D(adMatTrans, noVertices);
	for(i=0; i<noVertices; i++)
	{
		if(state[i] == NV)
		{
			//push(s, i);
			state[i]=IS;
			discovery[i] = timer++;
			dfs(adMat, noVertices, i);
			printf("\n");
		}
	}
	printArray(discovery, noVertices);
	printArray(parent, noVertices);
	printArray(finish, noVertices);
	printArray(state, noVertices);
	for(i=0; i<noVertices; i++)
		state[i]=NV;
	while(allStates(noVertices)!=V)
	{
		int v = retFinishMax(noVertices);
		state[v] = IS;
		dfs(adMatTrans, noVertices, v);
		printf("\n");
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

void dfs(int **adMat, int noVertices, int source)
{
	int i;
	for (i = 0; i < noVertices; ++i)
	{
		if(adMat[source][i] == 1 && state[i]==NV)
		{
			//push(s, i);
			state[i]=IS;
			discovery[i] = timer++;
			parent[i] = source;
			dfs(adMat, noVertices, i);
		}
	}
	printf("%d ", source);
	state[source] = V;
	finish[source] = timer++;
}
