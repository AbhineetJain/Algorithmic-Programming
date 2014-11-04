#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char str[60];
	struct node *next;
};
typedef struct node node;

node **start;
node **tail;
int i=0;


void ins(node *, node *, char*);
void print(node *, node *);
void sort(node **, node **, char **, int, int);
void dequeue(node *, node *, char **);
char* strrev(char *s)
{
	int i, j;
	for(i=0, j=strlen(s)-1; i<j; j--, i++)
		s[i]=s[j]+s[i]-(s[j]=s[i]);
	return s;
}

int main()
{
	int tc;
	int i, size, j, k;
	scanf("%d", &tc);
	char **p=NULL;
	int max=0;
	for(i=0; i<tc; i++)
	{
		start=(node **)malloc(sizeof(node *)*10);
		tail=(node **)malloc(sizeof(node *)*10);
		for(j=0; j<10; j++){
			start[j]=(node *)malloc(sizeof(node));
			start[j]->next=NULL;
			tail[j]=(node *)malloc(sizeof(node));
			tail[j]->next=NULL;
		}
		max=0;
		scanf("%d", &size);
		p=(char **)malloc(sizeof(char *)*size);
		for(j=0; j<size; j++)
		{
			p[j]=(char *)malloc(sizeof(char)*50);
			scanf("%s", p[j]);
			if(strlen(p[j])>max) max=strlen(p[j]);
		}
		scanf("%d", &k);
		for(j=0; j<size; j++)
		{
			p[j]=strrev(p[j]);
//			printf("%s ", p[j]);
			while(strlen(p[j])<k) p[j][strlen(p[j])]='0';
			p[j]=strrev(p[j]);
//			printf("%s\n", p[j]);
		}
		for(j=0; j<k; j++)
		{
			sort(start, tail, p, size, j);
		}
		for(j=0; j<size; j++){
			for(k=0; p[j][k]!='\0'; k++)
				if(p[j][k]!='0')
					break;
			if(p[j][k]=='\0') printf("0");
			else{
				for(; p[j][k]!='\0'; k++)
					printf("%c", p[j][k]);
			}
			if(j!=size-1)
				printf(" ");
			else
				printf("\n");
		}
//		for(j=0; j<10; j++)
//			print(start[j], tail[j]);
	}
	return 0;
}

void sort(node **start, node **tail, char **p, int size, int k)
{
	int j, len;
	for(j=0; j<size; j++)
	{
		len=strlen(p[j])-1-k;
	//	printf("%d\n", p[j][len]-'0');
		ins(start[p[j][len]-'0'], tail[p[j][len]-'0'], p[j]);
	//	printf("%s %s\n", start[p[j][len]-'0']->next->str, tail[p[j][len]-'0']->next->str);
	}
	i=0;
	for(j=0; j<10; j++)
		dequeue(start[j], tail[j], p);
//	for(j=0; j<size; j++)
//		printf("%s\n", p[j]);
}

void ins(node *start, node *tail, char *string)
{
	node *new=(node *)malloc(sizeof(node));
	strcpy(new->str, string);
//	printf("%s\n", new->str);
	if(start->next==NULL){
//		printf("I was here at start\n");
		start->next=new;
		new->next=NULL;
		tail->next=new;
	}
	else
	{
		tail->next->next=new;
		new->next=NULL;
		tail->next=new;
	}
//	printf("%s %s\n", start->next->str, tail->next->str);
}

void dequeue(node *start, node *tail, char **p)
{
	node *temp=NULL;
	while(start->next!=NULL)
	{
		temp=start->next;
		start->next=start->next->next;
		strcpy(p[i], temp->str);
		i++;
	}
}


void print(node *start, node *tail)
{
	node *temp=start->next;
	if(temp==NULL) printf("Empty\n");
	else{
	while(temp!=tail->next)
	{
		printf("%s ", temp->str);
		temp=temp->next;
	}
	printf("%s", tail->next->str);
	printf("\n");
}
}
