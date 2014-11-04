#include<stdio.h>
#include<stdlib.h>

struct node{
	int coeff;
	int exp;
	struct node *next;
};
typedef struct node node;

node *p1=NULL;
node *p2=NULL;

int count=0;

node* indes(node *, int , int);
void print(node *);
node* addsub(node *, node *, int);
node* mult(node *, node *);


int main()
{
	int i, j, tc, m, n, a, b;
	scanf("%d", &tc);
	for(i=0; i<tc; i++)
	{
		scanf("%d%d", &m ,&n);
		p1=(node *)malloc(sizeof(node));
		p2=(node *)malloc(sizeof(node));
		p1->next=NULL;
		p1->exp=-1;
		p2->next=NULL;
		p2->exp=-1;
		for(j=0; j<m; j++)
		{
			scanf("%d%d", &a, &b);
			p1=indes(p1, a, b);
		}
		for(j=0; j<n; j++)
		{
			scanf("%d%d", &a, &b);
			p2=indes(p2, a, b);
		}
//		print(p1);
//		print(p2);
		node *p3=addsub(p1, p2, 1);
		printf("%d\n", count);
		print(p3);
		node *p4=addsub(p1, p2, 2);
		printf("%d\n", count);
		print(p4);
		node *p5=mult(p1, p2);
		printf("%d\n", count);
		print(p5);
	}
	return 0;
}

node* indes(node *start, int a, int b)
{
	node *head=start;
	if(start->exp<a)
	{
		node *new=(node *)malloc(sizeof(node));
		new->exp=a;
		new->coeff=b;
		new->next=start;
		start=new;
		return start;
	}
	else if(start->exp==a)
	{
		start->coeff+=b;
		if(start->coeff==0){
			node *temp=start;
			start=temp->next;
			free(temp);
			count--;
		}
		count--;
	}
	while(head->next!=NULL)
	{
		if(head->next->exp < a)
		{
			node *new=(node *)malloc(sizeof(node));
			new->exp=a;
			new->coeff=b;
			new->next=head->next;
			head->next=new;
			break;
		}
		else if(head->next->exp == a)
		{
			head->next->coeff+=b;
			if(head->next->coeff==0){
				node *temp=head->next;
				head->next=temp->next;
				free(temp);
				count--;
			}
			count--;
			break;
		}
		head=head->next;
	}
	if(head->next==NULL)
	{
		node *new=(node *)malloc(sizeof(node));
		new->exp=a;
		new->coeff=b;
		head->next=new;
		new->next=NULL;
	}
	return start;
}

void print(node *start)
{
	node *head=start;
	while(head->exp!=-1)
	{
		printf("%d %d\n", head->exp, head->coeff);
		head=head->next;
	}
}

node* addsub(node *p1, node *p2, int mode)
{
	node *head1=p1;
	node *head2=p2;
	node *addp=NULL;
	//node *temp=addp;
	addp=(node *)malloc(sizeof(node));
	//temp=addp;
	addp->exp=-1;
	count=0;
	while(head1->exp!=-1){
		addp=indes(addp, head1->exp, head1->coeff);
		count++;
		head1=head1->next;
	}
	while(head2->exp!=-1){
		if(mode ==1 ) addp=indes(addp, head2->exp, head2->coeff);
		else addp=indes(addp, head2->exp, head2->coeff*(-1));
		count++;
		head2=head2->next;
	}
/*	while(head1->exp!=-1 && head2->exp!=-1)
	{
	
		if(head1->exp > head2->exp)
		{
			temp->next=(node *)malloc(sizeof(node));
			temp->next->exp=head1->exp;
			temp->next->coeff=head1->coeff;
			temp=temp->next;
			head1=head1->next;
			count++;
		}
		else if(head1->exp < head2->exp)
		{
			temp->next=(node *)malloc(sizeof(node));
			temp->next->exp=head2->exp;
			temp->next->coeff=head2->coeff;
			temp=temp->next;
			head2=head2->next;
			count++;
		}
		else
		{
			temp->next=(node *)malloc(sizeof(node));
			temp->next->exp=head1->exp;
			temp->next->coeff=head1->coeff+head2->coeff;
			temp=temp->next;
			head1=head1->next;
			head2=head2->next;
			count++;
		}
	}
	if(head1->exp==-1)
	{
		while(head2->exp!=-1)
		{
			temp->next=(node *)malloc(sizeof(node));
			temp->next->exp=head2->exp;
			temp->next->coeff=head2->coeff;
			temp=temp->next;
			head2=head2->next;
			count++;
		}
	}
	else if(head2->exp==-1)
	{
		while(head1->exp!=-1)
		{
			temp->next=(node *)malloc(sizeof(node));
			temp->next->exp=head1->exp;
			temp->next->coeff=head1->coeff;
			temp=temp->next;
			head1=head1->next;
			count++;
		}
	}
	temp->next=(node *)malloc(sizeof(node));
	temp->next->exp=-1;
*/	return addp;	
}

node* mult(node *p1, node *p2)
{
	node *head1=p1;
	node *head2=p2;
	node *multp=(node *)malloc(sizeof(node));
	multp->exp=-1;
	count=0;
	while(head1->exp!=-1)
	{
		while(head2->exp!=-1)
		{
			multp=indes(multp, head1->exp+head2->exp, head1->coeff*head2->coeff);
			count++;
			head2=head2->next;
		}
		head2=p2;
		head1=head1->next;
	}
	return multp;
}
