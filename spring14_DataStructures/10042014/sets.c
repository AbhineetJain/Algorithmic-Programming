#include<stdio.h>
#include<stdlib.h>

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
	scanf("%d", &noVertices);
	sets = (element **)malloc(sizeof(element *)*noVertices);
	sizes = (int *)malloc(sizeof(int));
	int i;
	for(i=0; i<noVertices; i++)
	{
		sizes[i] = 0;
		makeSet(i);
		printSet(i);
	}
	unionSet(0, 1);
	printSet(0);
	printSet(1);
	printf("0 belongs to set %d\n", findSet(0));
	printf("1 belongs to set %d\n", findSet(1));
	unionSet(2, 3);
	printSet(3);
	printSet(2);
	printf("2 belongs to set %d\n", findSet(2));
	printf("3 belongs to set %d\n", findSet(3));
	printf("4 belongs to set %d\n", findSet(4));
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
