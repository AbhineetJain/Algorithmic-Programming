#include<stdio.h>
#include<stdlib.h>

#define V 0
#define NV 2
#define IP 1

struct node {
	int val;
	struct node *next;
};
typedef struct node node;

node **adlist=NULL;
int *d=NULL;
int *p=NULL;
int *state=NULL;
int max=0;
int count=0;

struct queue {
	int val;
	struct queue *next;
};
typedef struct queue queue;

queue *qf=NULL;
queue *qr=NULL;

void enq(queue *qf, queue *qr, int val);
int deq(queue *qf, queue *qr);
void printq(queue *qf, queue *qr);
//void add_edge(int u, int v);
//void remove_edge(int u, int v);
void printadlist(node **adlist, int vertices);
void bfs(node **adlist, int vertices, int start);
void print(int *, int);

int main()
{
	int i, j;
	int vertices, n, nval;
	qf = (queue *)malloc(sizeof(queue));
	qr = (queue *)malloc(sizeof(queue));
	qf->val=qr->val=-1;
	qf->next=qr->next=NULL;
	scanf("%d", &vertices);
	adlist=(node **)malloc(sizeof(node *)*vertices);
	for(i=0; i<vertices; i++)
	{
		scanf("%d", &n);
		adlist[i]=(node *)malloc(sizeof(node));
		adlist[i]->val=i;
		adlist[i]->next=NULL;
		node *head = adlist[i];
		for(j=0; j<n; j++)
		{
			scanf("%d", &nval);
			node *new=(node *)malloc(sizeof(node));
			new->val=nval;
			new->next=NULL;
			head->next=new;
			head=new;
		}
	}
	printadlist(adlist, vertices);
	int bfsstart=0;
	scanf("%d", &bfsstart);
	while(bfsstart!=-1) {
		bfs(adlist, vertices, bfsstart);
		if(count>max) max=count;
		count=0;
		print(p, vertices);
		print(d, vertices);
		print(state, vertices);
		scanf("%d", &bfsstart);
	}
	return 0;
}

/*void add_edge(int u, int v)
{
	int nval;
	node *temp, *head=adlist[u];
	scanf("%d", &nval);
	node *new=(node *)malloc(sizeof(node));
	new->val=nval;
	temp=head->next;
	new->next=temp;
	head->next=new;
}*/

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
	printf("Enter bfs\n");
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
		count++;
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
