#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

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
	char str[500];
	int tc;
	scanf("%d", &tc);
	int i, j, k=0;
	char ch;
	int count;
	s=(node *)malloc(sizeof(node));
	for(i=0; i<tc; i++)
	{
		scanf("%s", str);
		s->next=NULL;
		s->b='a';
		char out[50];
		for(j=0; out[j]!='\0'; j++)
			out[j]='\0';
		for(j=0, k=0; str[j]!='\0'; j++)
		{
			switch(str[j]){
				case '^':
					push(s, str[j]);
					break;
				
				case '/': case '*': 
					if(s->next!=NULL){
						while((s->next!=NULL) && (s->next->b == '/' || s->next->b == '*' || s->next->b == '^'))
							out[k++] = pop(s);
					}
					push(s, str[j]);
					break;
				case '+': case '-':
					if(s->next!=NULL){
						while((s->next!=NULL) && (s->next->b == '+' || s->next->b == '*' || s->next->b == '/' || s->next->b == '-'|| s->next->b == '^'))
							out[k++] = pop(s);
					}
					push(s, str[j]);
					break;
				case '(': push(s, str[j]);
					  break;
				case ')': while(s->next!=NULL && s->next->b!='(')
						out[k++] = pop(s);
					  char del = pop(s);
					  break;
				default: out[k++] = str[j];
					 break;
			}
		}
		while(s->next!=NULL)
			out[k++]=pop(s);
		printf("%s\n", out);
		

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
	if(temp == NULL) printf("Stack is empty!");
	while(temp!=NULL)
	{
		printf("%c", temp->b);
		temp=temp->next;
	}
	printf("\n");
}
