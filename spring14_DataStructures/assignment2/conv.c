#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*Add balancing parantheses if not accepted*/

struct node{
	char b;
	struct node *next;
};
typedef struct node node;

node *s=NULL;

void push(node *, char);
void print(node *);
char pop(node *);
int isop(char);
int valid(char *);

int main()
{
	char str[50];
	int tc;
	scanf("%d", &tc);
	int i, j, l, k=0;
	char ch;
	int count;
	s=(node *)malloc(sizeof(node));
	for(i=0; i<tc; i++)
	{
		scanf("%s", str);
		if(!valid(str))
			printf("invalid\n");
		else{
			s->next=NULL;
			s->b='a';
			char out[50];
			for(j=0; out[j]!='\0'; j++)
				out[j]='\0';
			for(j=strlen(str)-1, k=0; j>=0; j--)
			{
				switch(str[j]){
					case '^':
	/*					if(s->next!=NULL){
						while((s->next!=NULL)&&)
							push(s, str[j]);
						break;
	 */				case '/': case '*': 
						if(s->next!=NULL){
							while((s->next!=NULL) && (s->next->b == '^'))
								out[k++] = pop(s);
						}
						push(s, str[j]);
						break;
					case '+': case '-':
						if(s->next!=NULL){
							while((s->next!=NULL) && (s->next->b == '*' || s->next->b == '/' || s->next->b == '^'))
								out[k++] = pop(s);
						}
						push(s, str[j]);
						break;
					case ')': push(s, str[j]);
						  break;
					case '(': while(s->next!=NULL && s->next->b!=')')
							  out[k++] = pop(s);
						  char del = pop(s);
						  break;
					default: out[k++] = str[j];
						 break;
				}
			}
			while(s->next!=NULL)
				out[k++]=pop(s);
			for(j=strlen(out)-1; j>=0; j--)
				printf("%c", out[j]);
			printf("\n");
		}
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
	printf("%c\n", ch);
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

int isop(char a)
{
	if(a=='+' || a=='*' || a=='/' || a=='-' || a=='^')
		return 1;
	else
		return 0;
}


int valid(char str[])
{
	int i, j;
	for(i=0; str[i+1]!='\0'; i++)
	{
		if( isop(str[i]) && isop(str[i+1]) )
			return 0;
		else if( isop(str[i]) && (str[i+1] == ')'))
			return 0;
		else if( isdigit(str[i]) && !(isop(str[i+1]) || str[i+1]==')' || str[i+1]=='\0'))
			return 0;
	}
	return 1;
}
