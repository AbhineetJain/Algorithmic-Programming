#include<stdio.h>
#include<stdlib.h>

#define V 0
#define NV 2
#define IP 1

struct vertex {
	int v;
	int wt;
};
typedef struct vertex vertex;

struct queue {
	struct vertex val;
	struct queue *next;
};
typedef struct queue queue;

queue *qf=NULL;
queue *qr=NULL;

struct node {
	struct vertex val;
	struct node *next;
};
typedef struct node node;

node **adlist=NULL;
int *d=NULL;
int *p=NULL;
int *state=NULL;
node **headlist=NULL;

void enq(queue *qf, queue *qr, vertex val);
int deq(queue *qf, queue *qr);
void printq(queue *qf, queue *qr);
void printadlist(node **adlist, int vertices);
void bfs(node **adlist, int vertices, int start);
void print(int *, int);

int main()
{
	int i, j;
	int testCases;
	int vertices, s, d, w;
	int edges;
	scanf("%d", &testCases);
	int k;
	for(k=0; k<testCases; k++)
	{
		qf=qr=NULL;
		qf = (queue *)malloc(sizeof(queue));
		qr = (queue *)malloc(sizeof(queue));
		qf->val.val=qr->val.val=-1;
		qf->val.wt=qr->val.wt=-1;
		qf->next=qr->next=NULL;
		scanf("%d%d", &vertices, &edges);
		adlist=(node **)malloc(sizeof(node *)*vertices);
		for(i=0; i<edges; i++)
		{
			scanf("%d%d%d", &s, &d, &w);
			adlist[s]=(node *)malloc(sizeof(node));
			adlist[s]->val=1;
			adlist[s]->next=NULL;
			//node *head = adlist[i];
			node *new=(node *)malloc(sizeof(node));
			new->val->val=d;
			new->val->wt=w;
			new->next=NULL;
			head->next=new;
			head=new;
		}
		printadlist(adlist, vertices);
		int bfsstart;
		scanf("%d", &bfsstart);
		bfs(adlist, vertices, bfsstart);
		print(p, vertices);
		print(d, vertices);
	}
	return 0;
}

void printadlist(node **adlist, int vertices)
{
	int i=0;
	for(i=0; i<vertices; i++)
	{
		node *head=adlist[i];
		while(head!=NULL)
		{
			printf("%d ", head->val);
			head=head->next;
		}
		printf("\n");
	}
}

void enq(queue *qf, queue *qr, int val)
{
	queue *new = (queue *)malloc(sizeof(queue));
	new->val=val;
	new->next=NULL;
	if(qr->next!=NULL) qr->next->next = new;
	qr->next=new;
	if(qf->next == NULL)
		qf->next = new;
}

int deq(queue *qf, queue *qr)
{
	queue *del=NULL;
	if(qf->next==NULL) printf("Queue is empty!\n");
	else
	{
		del = qf->next;
		qf->next = qf->next->next;
		int ret = del->val;
		free(del);
		return ret;
	}
	return -1;
}

void bfs(node **adlist, int vertices, int bfsstart)
{
	int v;
//	printf("Enter bfs\n");
	d=(int *)malloc(sizeof(int)*vertices);
	p=(int *)malloc(sizeof(int)*vertices);
	state=(int *)malloc(sizeof(int)*vertices);
	int i;
	for(i=0; i<vertices; i++)
	{
//		printf("Init\n");
		p[i]=-1;
		state[i]=NV;
		d[i]=100000;
	}
	enq(qf, qr, bfsstart);
	d[bfsstart]=0;
	state[bfsstart]=IP;
	p[bfsstart]=-1;
	while(qf->next!=NULL)
	{
		v = deq(qf, qr);
		printf("%d\n", v);
		//printq(qf, qr);
		node *head = adlist[v]->next;
//		printf("%d %d\n", adlist[v]->val, head->val);
		while(head!=NULL)
		{
			if(state[head->val]==NV)
			{
				state[head->val]=IP;
				d[head->val] = d[v]+1;
				p[head->val] = v;
				enq(qf, qr, head->val);
			}
			//printq(qf, qr);
			head = head->next;
		}
		state[v] = V;
	}
}

void print(int *a, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("%d: %d; ", i, a[i]);
	}
	printf("\n");
}

void printq(queue *qf, queue *qr)
{
	if(qf->next==NULL) printf("Queue is empty!\n");
	else {
		queue *temp = qf->next;
		while(temp!=NULL){
			printf("%d ", temp->val);
			temp = temp->next;
		}
		printf("\n");
	}
}
