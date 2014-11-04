#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct node{
	int a;
	struct node *next;
};
typedef struct node node;

node *s=NULL;

void push(node *, int);
int pop(node *);
void print(node *);
int isop(char);
int valid(char *);

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
		int checkz=0;
//		printf("Enter postfix expression: ");
		scanf("%s", str);
		if(!valid(str)) printf("invalid\n");
		else{
		 for(j=strlen(str)-1; j>=0; j--)
		 {
			switch(str[j]){
				case '^':
					op1=pop(s);
					op2=pop(s);
					temp = pow(op1, op2);
					push(s, temp);
					break;
				case '/':
					op1=pop(s);
					op2=pop(s);
					if(op2==0){
						printf("invalid\n");
						checkz=1;
						break;
					}
					temp=op1/op2;
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
					temp=op1-op2;
					push(s, temp);
					break;
				default:
					push(s, str[j]-'0');
					break;
			}
			if(checkz==1)
			 break;
		 }
		 if(checkz!=1)
		 	print(s);
		}
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
		printf("Stack is empty!\n");
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

int isop(char a)
{
	if(a=='+' || a=='/' || a=='-' || a=='*' || a=='^' )
		return 1;
	else
		return 0;
}

int valid(char a[])
{
	int i;
	int l=strlen(a);
	int op=0, dig=0;
	if(!isop(a[0])) return 0;
	if(!isdigit(a[l-1]) || !isdigit(a[l-2])) return 0;
	for(i=0; a[i]!='\0'; i++)
	{	
		if(isop(a[i])) op++;
		else if(isdigit(a[i])) dig++;
	}
	if(op!=(dig-1))
		return 0;
	return 1;
}
