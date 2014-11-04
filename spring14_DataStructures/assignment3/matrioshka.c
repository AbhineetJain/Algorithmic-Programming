#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


struct node{
	int a;
	struct node *next;
	int sum;
};
typedef struct node node;

node *s1 = NULL;

void push(node *, int);
//void print(node *);
int pop(node *);

int main()
{
	s1=(node *)malloc(sizeof(node));
	s1->a=1;
	s1->sum=0;
	s1->next=NULL;
	int tc, j;
	int inp, size, i;
	scanf("%d", &tc);
	for(j=0; j<tc; j++)
	{
		scanf("%d", &size);
		i=0;
		int count = 0;
		s1->next=NULL;
		while(i<size)
		{
			scanf("%d", &inp);
			if(inp < 0){
				push(s1, inp);
				if(s1->next->next){
					s1->next->next->sum+=(-1)*inp;
					if(s1->next->next->sum >= (-1)*(s1->next->next->a)){
						count=1;
					}
				}
			}
			else {
				if(s1->next!=NULL)
				{	int val = pop(s1);
					if(val != (-1)*inp || (s1->next==NULL && i!=size-1))
						count=1;
					
				}
				else
					count=1;
			}
			i++;
		}
		if(count == 1 || s1->next!=NULL) printf(":-( Try again.\n");
		else printf(":-) Matrioshka!\n");
	}
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
		add->a=val;
		add->sum=0;
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
		val=del->a;
		free(del);
	}
	return val;
}

/*void print(node *s)
{
	node *temp=NULL;
	temp=s->next;
	if(temp == NULL) printf("Stack is empty!");
	while(temp!=NULL)
	{
		printf("%d ", temp->a);
		temp=temp->next;
	}
	printf("\n");
}*/
