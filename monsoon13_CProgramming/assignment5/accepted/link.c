#include<stdio.h>
#include<stdlib.h>

long long beauty=0;

long long mypow(long long base, long long exp)
{
	base%=1000000007;
	long long result = 1;
	while(exp)
	{
		if(exp&1)
			result=(result*base)%1000000007;
		exp>>=1;
		base=(base*base)%1000000007;
	}
	return result;
}

struct list{
	int  rank;
	int  key;
	struct list *next;
	struct list *prev;
};
typedef struct list list;

struct point{
	struct list *start;
	struct list *tail;
};
typedef struct point point;

point *insert(point *ll, int m);
//void print(point *ll);
point *rotcl(point *ll, long long int cl);
void calc(point *ll1, point *ll2);
point *rotan(point *ll, long long int an);
point *delh(point *ll1);
point *delt(point *ll1);




int main()
{
	point *ll1=NULL, *ll2=NULL;
	int  val;
	int  m, nquery;
	scanf("%d %d", &m, &nquery);
	int i;
	ll1=insert(ll1, m);
	ll2=insert(ll2, m);
	list *temp=ll1->start;
	for(i=0; i<m; i++)
	{
		scanf("%d", &val);
		temp->rank=val;
		temp=temp->next;
	}
	temp=ll2->start;
	for(i=0; i<m; i++)
	{
		scanf("%d", &val);
		temp->rank=val;
		temp=temp->next;
	}
//	print(ll1);
//	print(ll2);
	calc(ll1, ll2);
	int q;
	long long int cl, an;
	char del[5];
	int x;
	long long tempb;
	for(i=0; i<nquery; i++)
	{
		scanf("%d", &q);
		switch(q)
		{
			case 1: scanf("%s", del);
				if(strcmp(del, "tail")==0)
				{
					tempb=(mypow((long long)ll1->tail->key,(long long)ll2->tail->rank)+mypow((long long)ll2->tail->key,(long long)ll1->tail->rank))%1000000007;
					beauty-=tempb;
					if(beauty<0) beauty+=1000000007;
					ll1=delt(ll1);
					ll2=delt(ll2);
//					calc(ll1,ll2);
				}
				else if(strcmp(del, "head")==0)
				{
					
					tempb=(mypow((long long)ll1->start->key,(long long)ll2->start->rank)+mypow((long long)ll2->start->key,(long long)ll1->start->rank))%1000000007;
					beauty-=tempb;
					if(beauty<0) beauty+=1000000007;
					ll1=delh(ll1);
					ll2=delh(ll2);
				//	calc(ll1,ll2);
				}
//				print(ll1);
//				print(ll2);
				m=m-1;
				printf("done\n");
				break;
			case 2: scanf("%lld %lld", &cl, &an);
				cl=cl%(long long)m;
				an=an%(long long)m;
				x=m/2+1;
				if(cl==0&&an==0)
					printf("%lld\n", beauty);
				else{
					if(cl<x){
						ll1=rotcl(ll1, cl);
//						printf("Normal\n");
					}
					else
						ll1=rotan(ll1, m-cl);
					if(an<x){
						ll2=rotan(ll2, an);
//						printf("Normal\n");
					}
					else
						ll2=rotcl(ll2, m-an);
					calc(ll1, ll2);
//					print(ll1);
//					print(ll2);
					printf("%lld\n", beauty);
				}
				break;
		}
	}
	return 0;
}

point *insert(point *ll, int m)
{
	int val;
	scanf("%d", &val);
	if(ll==NULL){
		ll=(point *)malloc(sizeof(point));
		ll->start=(list *)malloc(sizeof(list));
		ll->start->prev=ll->start;
		ll->start->next=ll->start;
		ll->tail=ll->start;
		ll->start->key=val;
	}
	int i;
	for(i=0; i<m-1; i++){
		scanf("%d", &val);
		ll->tail->next=(list *)malloc(sizeof(list));
		ll->tail->next->key=val;
		ll->tail->next->prev=ll->tail;
		ll->tail=ll->tail->next;
		ll->tail->next=ll->start;
		ll->start->prev=ll->tail;
	}
	return ll;
}

/*void print(point *ll)
{
	if(ll==NULL||ll->start==NULL)
		printf("List is empty\n");
	else{
		list *temp=ll->start;
		printf("(%u,%u) ", temp->rank, temp->key);
		temp=temp->next;
		while(temp!=ll->start)
		{
			printf("(%u,%u) ", temp->rank, temp->key);
			temp=temp->next;
		}
		printf("\n");
	}
}*/

point *rotcl(point *ll, long long int cl)
{
	list *temp1, *temp2;
	long long j;
	for(j=0; j<cl; j++){
		temp2=ll->start->next;
		temp1=ll->tail;
		ll->tail=ll->start;
		ll->start=temp2;
		ll->tail->prev=temp1;
	}
	return ll;
}

void calc(point *ll1, point *ll2)
{
	list *temp1=ll1->start;
	list *temp2=ll2->start;
	long long temp;
	beauty=0;
	temp=(mypow((long long)temp1->key,(long long)temp2->rank)+mypow((long long)temp2->key,(long long)temp1->rank))%1000000007;
	beauty=(beauty+temp)%1000000007;
	temp1=temp1->next;
	temp2=temp2->next;
	while(temp1!=ll1->start)
	{
		temp=(mypow((long long)temp1->key,(long long)temp2->rank)+mypow((long long)temp2->key,(long long)temp1->rank))%1000000007;
		beauty=(beauty+temp)%1000000007;
		temp1=temp1->next;
		temp2=temp2->next;
	}
}

point *rotan(point *ll, long long int an)
{
	list *temp1, *temp2;
	long long j;
	for(j=0; j<an; j++){
		temp2=ll->tail->prev;
		temp1=ll->start;
		ll->start=ll->tail;
		ll->tail=temp2;
		ll->start->next=temp1;
	}
	return ll;
}

point *delh(point *ll)
{
	list *temp=ll->start;
	ll->start=ll->start->next;
	ll->start->prev=ll->tail;
	ll->tail->next=ll->start;
	free(temp);
	return ll;
}

point *delt(point *ll)
{
	list *temp=ll->tail;
	ll->tail=ll->tail->prev;
	ll->tail->next=ll->start;
	ll->start->prev=ll->tail;
	free(temp);
	return ll;
}
