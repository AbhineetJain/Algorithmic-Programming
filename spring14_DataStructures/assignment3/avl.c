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

int setinc=0;
node *root=NULL;
node *new=NULL;

node* insert(node *, int);
void print(node *);
void balance(node *);
int height(node *);
void update(node *);

int main()
{
	int size, i, inp;
	scanf("%d", &size);
	for(i=0; i<size; i++)
	{
		scanf("%d", &inp);
		if(i==0) 
			root=insert(root, inp);
		else{
			setinc=0;
			root=insert(root, inp);
			update(new);
			print(root);
			balance(new);
		}
		print(root);
		printf("\n");
	}
	return 0;
}

node* insert(node *add, int val)
{
	if(add==NULL)
	{
		new=(node *)malloc(sizeof(node));
		new->data=val;
		new->left=NULL;
		new->right=NULL;
		new->parent=NULL;
		new->depthleft=0;
		new->depthright=0;
		return new;
	}
	else
	{
		if(add->data < val)
		{
			add->right=insert(add->right, val);
			add->right->parent=add;
//			if(new->parent->left == NULL) setinc = 1;
//			if(setinc) add->depthright+=1;
//			if(new->parent->data == add->data) new->parent->depthright=1;
			return add;
		}
		else if (add->data > val)
		{
			add->left=insert(add->left, val);
			add->left->parent=add;
//			if(new->parent->right == NULL) setinc = 1;
//			if(setinc) add->depthleft+=1;
//			if(new->parent->data == add->data) new->parent->depthleft=1;
			return add;
		}
	}
}

void balance(node *leaf)
{
	node *temp=NULL, *temp2=NULL, *temp3=NULL, *temp4=NULL, *temp5=NULL;
	if(leaf == NULL) return;
	if(abs(leaf->depthleft - leaf->depthright) < 2){
		balance(leaf->parent);
		return;
	}
	else
	{
		printf("I entered else\n");
//		printf("%d - dl: %d, dr: %d %d - dll: %d, dlr: %d\n", leaf->data, leaf->depthleft, leaf->depthright, leaf->left->data, leaf->left->depthleft, leaf->left->depthright);
		if(leaf->depthleft > leaf->depthright && leaf->left->depthleft > leaf->left->depthright)
		{
			printf("I entered left left\n");
			int child;
			if(leaf->parent!=NULL){
				if(leaf->parent->left->data == leaf->data)
					child=0;
				else
					child=1;
			}
			temp=leaf;
			leaf=leaf->left;
			leaf->parent=temp->parent;
			if(leaf->parent == NULL) root=leaf;
			else {
				if(child==0){ leaf->parent->left=leaf; leaf->parent->depthleft-=1; }
				else{ leaf->parent->right=leaf; leaf->parent->depthright-=1; }
			}
			temp2=leaf->right;
			leaf->right=temp;
			temp->parent=leaf;
			temp->left=temp2;
			if(temp2) temp2->parent=temp;
			temp->depthleft=height(temp->left);
			leaf->depthright=height(leaf->right);
		}
		else if(leaf->depthright > leaf->depthleft && leaf->right->depthright > leaf->right->depthleft)
		{
			printf("I entered right right\n");
			int child;
			if(leaf->parent!=NULL){
				if(leaf->parent->left->data == leaf->data)
					child=0;
				else
					child=1;
			}
			temp=leaf;
			leaf=leaf->right;
			leaf->parent=temp->parent;
			if(leaf->parent == NULL) root=leaf;
			else {
				if(child==0){ leaf->parent->left=leaf; leaf->parent->depthleft-=1; }
				else{ leaf->parent->right=leaf; leaf->parent->depthright-=1; }
			}
			temp2=leaf->left;
			leaf->left=temp;
			temp->parent=leaf;
			temp->right=temp2;
			if(temp2) temp2->parent=temp;
			temp->depthright=height(temp->right);
			leaf->depthleft=height(leaf->left);
		}
		else if(leaf->depthleft > leaf->depthright && leaf->left->depthright > leaf->left->depthleft)
		{
			printf("I entered left right\n");
			int child;
			if(leaf->parent!=NULL){
				if(leaf->parent->left->data == leaf->data)
					child=0;
				else
					child=1;
			}
			temp=leaf;
			temp2=leaf->left;
			temp3=leaf->left->right;
			leaf=temp3;
			leaf->parent=temp->parent;
			if(leaf->parent == NULL) root=leaf;
			else {
				if(child==0){ leaf->parent->left=leaf; leaf->parent->depthleft-=1; }
				else{ leaf->parent->right=leaf; leaf->parent->depthright-=1; }
			}
			temp->parent=leaf;
			temp4=leaf->right;
			temp->left=temp4;
			temp4->parent=temp;
			leaf->right=temp;
			temp5=leaf->left;
			leaf->left=temp2;
			temp2->parent=leaf;
			temp2->right=temp5;
			temp5->parent=temp2;
			leaf->depthleft=height(leaf->left);
			leaf->depthright=height(leaf->right);
			temp2->depthright=height(temp2->right);
			temp->depthleft=height(temp->left);
		}
		balance(leaf->parent);
		return;
	}
}

void print(node *head)
{
	if(head!=NULL){
		if(head->parent!=NULL)
			printf("%d l:%d r:%d parent:%d\n", head->data, head->depthleft, head->depthright, head->parent->data);
		else
			printf("%d l:%d r:%d\n", head->data, head->depthleft, head->depthright);
		print(head->left);
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

void update(node *new)
{
	node *temp = new;
	while(temp!=NULL)
	{
		temp->depthright=height(temp->right);
		temp->depthleft=height(temp->left);
		temp=temp->parent;
	}
}

