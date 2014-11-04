#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int a;
	struct node *next;
};
typedef struct node node;

node *s=NULL;

void push(node *, int);
int pop(node *);
void print(node *);

int main()
{
	char str[50];
	int t;
	int i, j;
	int op1, op2, temp;
//	printf("Enter number of testcases: ");
	scanf("%d", &t);
	s=(node *)malloc(sizeof(node));
	for(i=0; i<t; i++)
	{
		s->next=NULL;
		s->a=1;
//		printf("Enter postfix expression: ");
		scanf("%s", str);
		for(j=0; str[j]!='\0'; j++)
		{
			switch(str[j]){
				case '^':
					op1=pop(s);
					op2=pop(s);
					temp = pow(op2, op1);
					push(s, temp);
					break;
				case '/':
					op1=pop(s);
					op2=pop(s);
					temp=op2/op1;
					push(s, temp);
					break;
				case '*':
					op1=pop(s);
					op2=pop(s);
					temp=op2*op1;
					push(s, temp);
					break;
				case '+':
					op1=pop(s);
					op2=pop(s);
					temp=op2+op1;
					push(s, temp);
					break;
				case '-':
					op1=pop(s);
					op2=pop(s);
					temp=op2-op1;
					push(s, temp);
					break;
				default:
					push(s, str[j]-'0');
					break;
			}
		
		}
		print(s);
	}
	return 0;
}


void push(node *s, int val)
{
	node *add = NULL;
	add = (node *)malloc(sizeof(node));
	if (add == NULL)
		printf("Insufficient Memory!\n");
	else{
		node *temp = s->next;
		s->next=add;
		add->next=temp;
		add->a=val;
	}
}

int pop(node *s)
{
	node *del = NULL;
	int val;
	if (s->next == NULL)
		printf("Stack is Empty!");
	else
	{
		del = s->next;
		s->next = del->next;
		val = del->a;
		free(del);
	}
	return val;
}

void print(node *s)
{
	node *temp=NULL;
	temp=s->next;
	if(temp==NULL) printf("Stack is Empty!\n");
	while(temp!=NULL){
		printf("%d\n", temp->a);
		temp=temp->next;
	}
}


