#include<stdio.h>
#include<stdlib.h>

struct node{
	int a;
	struct node *next;
};
typedef struct node node;

node *qf = NULL;
node *qr = NULL;
int size=0;

void enq(node *, node *, int);
int deq(node *, node *);
void print(node *, node *);

int main()
{
	int op;
	int add, del, count;
	qf=(node *)malloc(sizeof(node));
	qf->next = NULL;
	qf->a = 1;
	qr=(node *)malloc(sizeof(node));
	qr->next = NULL;
	qr->a=2;
	do{
		scanf("%d", &op);
		switch(op){
			case 1:	
				scanf("%d", &add);
				enq(qf, qr, add);
				break;
			case 2:
				count=0;
				while(count<(size-1)){
					enq(qf, qr, deq(qf, qr));
					count++;

				}
				del=deq(qf, qr);
				if(del!=-1)
					printf("Element popped: %d\n", del);
				break;
			case 3:
				print(qf, qr);
				break;
			case 4:
				printf("Bye\n");
				break;
		}
	}while(op!=4);
	return 0;
}

void enq(node *qf, node *qr, int val)
{
	node *add = NULL;
	add = (node *)malloc(sizeof(node));
	if(add == NULL) printf("Insufficient Memory!\n");
	else{
		add->a = val;
		add->next = NULL;
		if(qr->next!=NULL) qr->next->next = add;
		qr->next = add;
		if(qf->next == NULL){
			qf->next = add;

		}
		size++;
	}
}

int deq(node *qf, node *qr)
{
	node *del=NULL;
	if(qf->next == NULL) printf("Queue is empty\n");
	else{
		del = qf->next;
		qf->next = qf->next->next;
		int ret = del->a;
		free(del);
		size--;
		return ret;
	}
	return -1;
}

void print(node *qf, node *qr)
{
	node *temp=qf->next;
	if(temp==NULL) printf("Queue is empty!\n");
	while(temp!=NULL){
		printf("%d ", temp->a);
		temp=temp->next;
	}
	printf("\n");
}
