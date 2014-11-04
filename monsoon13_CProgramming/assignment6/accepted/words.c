#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct words{
	char word[15];
	struct words *next;
}node;

void insert();
void delete();
void printx();

node *ptrarr[26];

int main()
{
	int n;
	scanf("%d", &n);
//	printf("%d\n", n);
	int i;
	for(i=0; i<26; i++)
		ptrarr[i]=NULL;
	for(i=0; i<n; i++)
		insert();
	int nq, q;
//	printf("Insert\n");
	scanf("%d", &nq);
//	printf("%d\n", nq);
	for(i=0; i<nq; i++)
	{
		scanf("%d", &q);
//		printf("%d\n", q);
		switch(q)
		{
			case 1: insert();
				break;
			case 2: delete();
				break;
			case 3: printx();
				break;
		}
	}
	return 0;
}

void insert()
{
	char inw[15];
	scanf("%s", inw);
	node *head=ptrarr[inw[0]-97];
	node *temp;
	node *add=(node *)malloc(sizeof(node));
	strcpy(add->word, inw);
	if(head==NULL){ ptrarr[inw[0]-97]=add; add->next=NULL;}
	else{
		if(strcmp(inw, head->word)<0){
			add->next=head;
			ptrarr[inw[0]-97]=add;
		}
		else{
			while(head->next!=NULL){
				if(strcmp(inw, head->next->word)<0){
					temp=head->next;
					head->next=add;
					add->next=temp;
					break;
				}
				else
					head=head->next;
			}
			if(head->next==NULL){
				head->next=add;
				add->next=NULL;
			}
		}
	}
}

void printx()
{
	char alpha;
	getchar();
	alpha=getchar();	
	node *head=ptrarr[alpha-97];
	if(head==NULL) printf("\n");
	else{
		while(head!=NULL)
		{
			printf("%s\n", head->word);
			head=head->next;
		}
	}
}

void delete()
{
	char delw[15];
	scanf("%s", delw);
	node *head=ptrarr[delw[0]-97];
	if(head!=NULL){
		if(strcmp(delw,head->word)==0){
			ptrarr[delw[0]-97]=head->next;
		}
		else{
			while(head->next!=NULL){
				if(strcmp(delw,head->next->word)==0){
					head->next=head->next->next;
					break;
				}
				else
					head=head->next;
			}
		}
	}
}

			
