/* Program to insert in a linked list, count the number of nodes, print the linked list
and delete a value from the linked list*/

#include<stdio.h>
#include<stdlib.h>

typedef struct element{
	int n;
	struct element *next;
}node;


node* del(node *start, int m);		//deletes the value m from the linked list
void print(node *start);		//prints the linked list and the number of nodes in the linked list
node* ins(node *start, int m);		//inserts a new element in the linked list and returns the pointer to starting node

//ALternate merging of two lists
node* merge(node *start1, node *start2){
	node *temp1=start1, *temp2=start2, *head1=start1, *head2=start2;
	while(head2!=NULL)
	{
		temp2=head2->next;
		if(head1!=NULL){
			temp1=head1->next;
			head1->next=head2;
			head1=temp1;
			if(temp1!=NULL)
				head2->next=temp1;
		}
		head2=temp2;
	
	}
	return start1;
}

//Inserting an element in order in a sorted list
node* insasc(node *start, int m)
{
	node *head=start;
	node *new=(node *)malloc(sizeof(node));
	new->n=m;
	if(start->n<m)
	{
		new->next=start;
		start=new;
		return start;
	}
	while(head->next!=NULL)
	{
		if(head->next->n < m)
		{
			new->next=head->next;
			head->next=new;
			break;
		}
		head=head->next;
	}
	if(head->next==NULL)
	{	
		head->next=new;
		new->next=NULL;
	}
	return start;
}
/*Alternate
node *temp, *dummy, *prev;
temp=start;
prev=NULL;
while(temp){
	if(temp->val>=m)
		break;
	prev=temp;
	temp=temp->next;
}
dummy=malloc()
dummy->val=m;
dummy->next=temp;
if(prev==NULL)return dummy;
else{
	prev->next=dummy;
	return start;
}
*/

//Inserting an element in nth position in a list
node* insatn(node *start)
{
	int m, val;
	scanf("%d%d", &m, &val);
	node *head=start;
	node *new=(node *)malloc(sizeof(node));
	new->n=val;
	int count=0;
	if(start==NULL){
		new->next=start;
		start=new;
	}
	else{
		if(m!=0){
			while(count<m-1 && head->next!=NULL)
			{
				head=head->next;
				count++;
			}
			new->next=head->next;
			head->next=new;
		}
		else{
			new->next=head;
			head=new;
			start=new;
		}
	}
	return start;
}
int main()
{
	node *start1=NULL, *start2=NULL;
	int m;
	int n, i;
//	printf("How many values do you want to insert? ");
	scanf("%d",&n);
	start1=(node *)malloc(sizeof(node));
	start1->n=-1;
	start1->next=NULL;
	for(i=0; i<n; i++)
	{	scanf("%d", &m);
		start1=insasc(start1, m);
	}
	print(start1);
//	start1=insasc(start1);
//	start1=insatn(start1);
/*	print(start1);
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{	scanf("%d", &m);
		start2=ins(start2, m);
	}
	print(start2);
	node *temp=start2;
	while(temp!=NULL){
		start1=insasc(start1, temp->n);
		temp=temp->next;
	}
//	start1=merge(start1,start2);
*/	print(start1);
/*	int  val;
	printf("How many values do you want to delete? ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{	
		scanf("%d", &val);
		start=del(start, val);
		print(start);
	}
*/	return 0;
}


node* ins(node *start, int m)
{
	node *new=(node *)malloc(sizeof(node));
	new->n=m;
	new->next=start;
	return new;
}

void print(node *start)
{
	int count=0;
	node *head=start;
	while(head!=NULL)
	{
		printf("%d -> ", head->n);
		head=head->next;
		count++;
	}
	printf("NULL\n");
	printf("Count:%d\n", count);
}


node* del(node *start, int m)
{
	int count=0;
	node *temp;
	if(start==NULL) return start;
	if(m==start->n)
	{
		temp=start;
		start=start->next;
		free(temp);
		return start;
	}
	else
	{
		node *head=start;
		while(head->next!=NULL)
		{
			if(head->next->n==m)
			{
				temp=head->next;
				head->next=head->next->next;
				count=1;
				free(temp);
			}
			head=head->next;
		}
		if(count==0)
			printf("Value not found\n");
		return start;
	}
}
/*Alternate

node *start, *curr, *prev;
int n;
scanf("%d", &n);
start=(node *)malloc(sizeof(node));
scanf("%d", &start->n);
prev=start;
n--;
while(n--)
{
	curr=(node*)malloc(sizeof(node));
	scanf("%d", &curr->n);
	prev->next=curr;
	prev=curr;
}

print....
*/
