#include<stdio.h>
#include<stdlib.h>

struct node{
	int a;
	struct node *left;
	struct node *right;
	int level;
};
typedef struct node node;

node *root=NULL;
int maxlevel=0;
node *lastnode = NULL;

void print(node *);
node* find(node *, int);
node* insrec(node *, int);

int main()
{
	int size;
	int i, inp;
	printf("Enter the no. of elements: ");
	scanf("%d", &size);
	for(i=0; i<size; i++){
		scanf("%d", &inp);
		root=insrec(root, inp);
		root->level = 0;
	}
	print(root);
	printf("%d\n", lastnode->a);
	return 0;
}


//Recursive Insert in a BST
node* insrec(node *root, int ip)
{
	if(root==NULL)
	{
		node *new=(node *)malloc(sizeof(node));
		new->a=ip;
		new->left=NULL;
		new->right=NULL;
//		new->level = 0;
		root=new;
		return root;
	}
	else
	{
		if(root->a < ip){
			root->right=insrec(root->right, ip);
			root->right->level = root->level + 1;
			if(root->right->level > maxlevel) maxlevel = root->right->level;
		}
		else if(root->a > ip){
			root->left=insrec(root->left, ip);
			root->left->level = root->level + 1;
			if(root->left->level > maxlevel) maxlevel = root->left->level;
		}
	}
	return root;
}

//Recursive Find/Search for a BST
node* find(node *root, int val)
{
	node *temp;
	if(root!=NULL)
	{
		if(root->a > val){
			temp=find(root->left, val);
			return temp;
		}
		else if(root->a < val){
			temp=find(root->right, val);
			return temp;
		}
	}
	return root;
}

//Recursive Inorder Printing of a BST : Sorted Order
void print(node *root)
{
	if(root!=NULL)
	{
		print(root->left);
		if(root->level == maxlevel) lastnode = root;
		print(root->right);
	}
}
