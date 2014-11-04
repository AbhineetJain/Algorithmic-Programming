#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node{
	int b;
	struct node *next;
};
typedef struct node node;

node *s1 = NULL;
node *s2 = NULL;


void push(node *, int);
void print(node *);
int pop(node *);

int main()
{
	int op, add, del;
	s1=(node *)malloc(sizeof(node));
	s1->b=1;
	s1->next=NULL;
	s2=(node *)malloc(sizeof(node));
	s2->b=1;
	s2->next=NULL;
	do{
		scanf("%d", &op);
		switch(op){
			case 1:
				scanf("%d", &add);
				push(s1, add);
				break;
			case 2:
				while(s1->next->next!=NULL) push(s2, pop(s1));
				del=pop(s1);
				if(del!=-1) printf("Element dequeued: %d\n", del);
				while(s2->next!=NULL) push(s1, pop(s2));
				break;
			case 3:
				print(s1);
				break;
			case 4:
				printf("Bye\n");
				break;
		}
	}while(op!=4);
	return 0;
}

void push(node *s, int val)
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
		add->b=val;
	}
}

int pop(node *s)
{
	node *del=NULL;
	int val=-1;
	if (s->next == NULL)
		printf("Stack is empty!\n");
	else
	{
		del=s->next;
		s->next=del->next;
		val=del->b;
		free(del);
	}
	return val;
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
