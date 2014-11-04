#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char ch;
	int freq;
	char code[10];
	struct node *left;
	struct node *right;
};
typedef struct node node;

struct queue{
        node *a;
        struct queue *next;
};
typedef struct queue queue;

queue *qf=NULL;
queue *qr=NULL;

node *root=NULL;
int *freqtable;
char **encoding;

void enq(queue *, queue *, node *);
node* deq(queue *, queue *);
void printq(queue *, queue *);
void create_node(node *, node *);
void print(node *);

int main()
{
	char string[100];
	char inpchar;
	int i=0;
	freqtable=(int *)malloc(sizeof(int)*128);
	encoding=(char **)malloc(sizeof(char *)*128);
	for(i=0; i<128; i++)
		encoding[i]=(char *)malloc(sizeof(char)*10);
	i=0;
	while(~(scanf("%c", &inpchar)))
	{
		string[i]=inpchar;
		freqtable[inpchar]+=1;
		i++;
	}
	int strlength=i;
	qf=(queue *)malloc(sizeof(queue));
	qf->next=NULL;
	qr=(queue *)malloc(sizeof(queue));
	node *new=NULL;
	qr->next=NULL;
	printf("%s", string);
	for(i=0; i<128; i++)
	{
		if(freqtable[i]){
			if(i==10) printf("\\n: %d\n", freqtable[i]);
			else if(i==32) printf("sp: %d\n", freqtable[i]);
			else printf("%c: %d\n", i, freqtable[i]);
			new=(node *)malloc(sizeof(node));
			new->ch=i;
			new->freq=freqtable[i];
			new->left=NULL;
			new->right=NULL;
			enq(qf, qr, new);
		}
	}
	printq(qf, qr);
	while(qf->next->next!=NULL)
		create_node(deq(qf, qr), deq(qf, qr));
	printq(qf, qr);
	root=deq(qf, qr);
	strcpy(root->left->code,"0");
	strcpy(root->right->code,"1");
	print(root);
	printf("\n");
	for(i=0; i<128; i++)
	{
		if(strlen(encoding[i]))
			if(i==10) printf("\\n: %s\n", encoding[i]);
			else if(i==32) printf("sp: %s\n", encoding[i]);
			else printf("%c: %s\n", i, encoding[i]);
	}
	char encodedstr[100];
	for(i=0; i<strlength; i++)
		strcat(encodedstr, encoding[string[i]]);
	printf("%s\n", encodedstr);
	node *temp=root;
	for(i=0; encodedstr[i]!='\0'; i++)
	{
		if(encodedstr[i]=='0')
			temp=temp->left;
		else
			temp=temp->right;
		if(temp->left==NULL && temp->right==NULL){
			printf("%c", temp->ch);
			temp=root;
		}
	}
	return 0;
}

void create_node(node *root1, node *root2)
{
	node* new = (node *)malloc(sizeof(node));
	new->freq = root1->freq + root2->freq;
	new->left = root1;
	new->right = root2;
	enq(qf, qr, new);
}

void enq(queue *qf, queue *qr, node* a)
{
	queue *add=NULL;
	add = (queue *)malloc(sizeof(queue));
	if(add == NULL) printf("Insufficient Memory!\n");
	else
	{
		add->a=(node *)malloc(sizeof(node));
		*add->a=*a;
		add->next=NULL;
		queue *temp=qf->next;
		if(temp!=NULL){
			if(temp->a->freq > add->a->freq)
			{
				qf->next=add;
				add->next=temp;
				
			}
			else
			{
				while(temp->next && temp->next->a->freq < add->a->freq)
					temp=temp->next;
				queue *temp2=temp->next;
				temp->next=add;
				add->next=temp2;
			}
		}
		else{
			qf->next=add;
		}
		if(qr->next == NULL)
			qr->next=add;
	}
}

node* deq(queue *qf, queue *qr)
{
	queue *del=NULL;
	if(qf->next == NULL) printf("Queue is empty!\n");
	else{
		del = qf->next;
		qf->next=qf->next->next;
		node *temp=NULL;
		temp=del->a;
		return temp;
	}
	return NULL;
}

void printq(queue *qf, queue *qr)
{
	queue *temp=qf->next;
	if(temp==NULL) printf("Queue is empty!\n");
	else{
		while(temp!=NULL)
		{
			printf("%d ", temp->a->freq);
			temp=temp->next;
		}
		printf("\n");
	}
}

void print(node *tree)
{
	if(tree!=NULL)
	{
		if(tree!=root && tree->left!=NULL) {
			strcpy(tree->left->code, tree->code);
			strcat(tree->left->code,"0");
		}
		if(tree!=root && tree->right!=NULL) {
			strcpy(tree->right->code, tree->code);
			strcat(tree->right->code, "1");
		}
		if(tree->right==NULL && tree->left==NULL){
			if(tree->ch == 10) printf("\\n %d %s\n", tree->freq, tree->code);
			else if(tree->ch == 32) printf("sp %d %s\n", tree->freq, tree->code);
			else printf("%c %d %s\n", tree->ch, tree->freq, tree->code);
			strcpy(encoding[tree->ch], tree->code);
		}
		print(tree->left);
		print(tree->right);
	}
}
