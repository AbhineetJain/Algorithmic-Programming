/*AVL Trees: Insertion hi ho jaaye! */

#include<stdio.h>
#include<stdlib.h>

struct node{
	int depthleft;
	int depthright;
	int data;
	struct node *parent;
	struct node *left;
	struct node *right;
};
typedef struct node node;

node *root=NULL;

node* insert(node *, int);
void print(node *);
void balance(node *);
int height(node *);

int main()
{
	int size, i, inp;
	scanf("%d", &size);
	for(i=0; i<size; i++)
	{
		scanf("%d", &inp);
		if(i==0) 
			root=insert(root, inp);
		else
			balance(insert(root, inp));
		print(root);
		printf("\n");
	}
	return 0;
}

node* insert(node *add, int val)
{
	if(add==NULL)
	{
		node *new=(node *)malloc(sizeof(node));
		new->data=val;
		new->left=NULL;
		new->right=NULL;
		add=new;
		new->parent=NULL;
		new->depthleft=0;
		new->depthright=0;
		return add;
	}
	else
	{
		if(add->data < val)
		{
			add->depthright+=1;
			add->right=insert(add->right, val);
			add->right->parent=add;
			return add->right;
		}
		else if (add->data > val)
		{
			add->depthleft+=1;
			add->left=insert(add->left, val);
			add->left->parent=add;
			return add->left;
		}
	}
}

void balance(node *leaf)
{
	node *temp=NULL, *temp2=NULL;
	if(leaf == NULL) return;
	if(abs(leaf->depthleft - leaf->depthright) < 2){
		balance(leaf->parent);
		return;
	}
	else
	{
		printf("I entered else\n");
		if(leaf->depthleft > leaf->depthright && leaf->left->depthleft > leaf->left->depthright)
		{
			temp=leaf;
			leaf=leaf->left;
			leaf->parent=temp->parent;
			temp2=leaf->right;
			leaf->right=temp;
			temp->parent=leaf;
			temp->left=temp2;
			temp2->parent=temp;
			temp->depthleft=height(temp->left);
			leaf->depthright=height(leaf->right);
		}
		balance(leaf->parent);
		return;
	}
}

void print(node *head)
{
	if(head!=NULL){
		print(head->left);
		printf("%d l:%d r:%d\n", head->data, head->depthleft, head->depthright);
		print(head->right);
	}
}

int height(node *head)
{
	if(head==NULL) return -1;
	if(head->left == NULL && head->right == NULL)
		return 0;
	else{
		int l = height(head->left);
		int r = height(head->right);
		return 1+((l>r)?l:r);
	}
}

