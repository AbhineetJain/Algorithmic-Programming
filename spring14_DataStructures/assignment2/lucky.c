#include<stdio.h>
#include<stdlib.h>

struct node{
	int a;
	struct node *next;
};
typedef struct node node;

node *start=NULL;
node *tail=NULL;

void ins(int);
void print(node *);
void del(node *, int);

int cmp(const void *a, const void *b)
{
	return ( *(int *)a - *(int *)b );
}

int n;

int main()
{
	int i, h;
	int j, tc, k;
	scanf("%d", &tc);
	int arr[1005];
	for(j=0; j<tc; j++)
	{
		start=NULL;
		tail=NULL;
		scanf("%d", &n);
		for(i=0; i<n; i++)
			scanf("%d", &arr[i]);
		scanf("%d", &k);
		qsort(arr, n, sizeof(int), cmp);
		for(i=0; i<n; i++)
			ins(arr[i]);
//		print(start);
		del(start, k);
	}
	return 0;
}

void ins(int m)
{
	node *new=(node *)malloc(sizeof(node));
	new->a=m;
	if(start==NULL){
		start=new;
		new->next=start;
		tail=start;
	}
	else{
		tail->next=new;
		new->next=start;
		tail=new;
	}
}

void print(node *start)
{
	node *temp=start;
//	if(start->next==start) printf("%d ", start->a);
	while(temp!=tail){
		printf("%d ", temp->a);
		temp=temp->next;
	}		
	printf("%d", tail->a);
	printf("\n");
}

void del(node *start, int val)
{
	int count=n, i;
	node *head=start;
	while(count!=1){
		i=1;
		while(i!=(val-1)%count){
			head=head->next;
			i++;
		}
		node *temp=head->next;
		head->next=temp->next;
//		printf("%d\n", temp->a);
		free(temp);
		count--;
		head=head->next;
	}
	printf("%d\n", head->a);
}
	
