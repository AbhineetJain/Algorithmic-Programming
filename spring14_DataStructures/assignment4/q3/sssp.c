#include<stdio.h>
#include<stdlib.h>
#include "heap.h"

int **adMat=NULL;
int **weight=NULL;
int *distance=NULL;
int *parent=NULL;

void print(int **mat, int size);
void BellFordAlgo(int, int ** , int);
void dijkstraAlgo(int, int **, int)

int main()
{
	int i, j, noVertices;
	scanf("%d", &noVertices);
	adMat = (int **)malloc(sizeof(int *)*noVertices);
	weight = (int **)malloc(sizeof(int *)*noVertices);
	distance = (int *)malloc(sizeof(int)*noVertices);
	parent = (int *)malloc(sizeof(int)*noVertices);
	for(i=0; i<noVertices; i++)
	{
		adMat[i] = (int *)malloc(sizeof(int)*noVertices);
		weight[i] = (int *)malloc(sizeof(int)*noVertices);
		for(j=0; j<noVertices; j++)
		{
			adMat[i][j]=0;
			weight[i][j]=0;
		}
	}
	for(i=0; i<noVertices; i++)
	{
		for(j=0; j<noVertices; j++)
		{
			scanf("%d", &adMat[i][j]);
			if(adMat[i][j] == 1)
				scanf("%d", &weight[i][j]);
		}
	}

	print(adMat, noVertices);
	print(weight, noVertices);
	int source;
	scanf("%d", &source);
	BellFordAlgo(noVertices, adMat, source);
	for(i=0; i<noVertices; i++)
		printf("%d ", distance[i] );
	printf("\n");
	for(i=0; i<noVertices; i++)
		printf("%d ", parent[i] );
	printf("\n");
	return 0;
}

void print(int **mat, int size)
{
	int i, j;
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}


void BellFordAlgo(int noVertices, int **adMat, int source)
{
	int i, j, k;
	for(i=0; i<noVertices; i++)
	{
		distance[i]=100000;
		parent[i]=-1;
	}
	distance[source] = 0;
	for(k=0; k<noVertices; k++)
	{
		for(i=0; i<noVertices; i++)
		{
			for(j=0; j<noVertices; j++)
			{
				if(adMat[i][j]==1)
				{
					if(distance[i] + weight[i][j] < distance[j])
					{
						distance[j] = distance[i] + weight[i][j];
						parent[j] = i;
					}
				}
			}
		}
	}
}

void dijkstra(int noVertices, int **adMat, int source)
{
	int i, j, k;
	for(i=0; i<noVertices; i++)
	{
		distance[i]=100000;
		parent[i]=-1;
	}
	distance[source] = 0;

