#include<stdio.h>
#include<stdlib.h>

struct node{
	char b;
	struct node *next;
};
typedef struct node node;

node *s=NULL;

void push(node *, char);
void print(node *);
char pop(node *);

int main()
{
	char str[50];
	int tc;
	printf("Enter no. of testcases: ");
	scanf("%d", &tc);
	int i, j;
	char ch;
	int count;
	s=(node *)malloc(sizeof(node));
	for(i=0; i<tc; i++)
	{
		scanf("%s", str);
		s->next=NULL;
		s->b='a';
		count = 0;
		for(j=0; str[j]!='\0'; j++)
		{
		//	printf("Enter\n");
			if(str[j] == '(' || str[j] == '[' || str[j] == '{'){
		//		printf("Pushed\n");
				push(s, str[j]);
			}
			else if(str[j] == ')' || str[j] == ']' || str[j] == '}')
			{
				ch = pop(s);
				switch(str[j]){
					case ')': if(ch == '('){
		//					printf("Enter 1\n");
							count++;
					          }
						  else{
							count = 0;
							break;
						  }
						  break;
					case ']': if(ch == '[')
							count++;
						  else{
							count = 0;
							break;
						  }
						  break;
					case '}': if(ch == '{')
							count++;
						  else{
							count = 0;
							break;
						  }
						  break;
				}
			}
		//	printf("%d\n", count);
		}
		if(count > 0)
			printf("Balanced\n");
		else
			printf("Not Balanced\n");
//		print(s);
	}	
	return 0;
}

void push(node *s, char ch)
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
		add->b=ch;
	}
}

char pop(node *s)
{
	node *del=NULL;
	char ch;
	if (s->next == NULL)
		printf("Stack is empty!\n");
	else
	{
		del=s->next;
		s->next=del->next;
		ch=del->b;
		free(del);
	}
	return ch;
}

void print(node *s)
{
	node *temp=NULL;
	temp=s->next;
	while(temp!=NULL)
	{
		printf("%c", temp->b);
		temp=temp->next;
	}
	printf("\n");
}
