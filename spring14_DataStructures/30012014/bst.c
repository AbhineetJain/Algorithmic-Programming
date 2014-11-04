#include<stdio.h>
#include<stdlib.h>

struct node{
	int a;
	struct node *left;
	struct node *right;
};
typedef struct node node;

node *root=NULL;

node* ins(node *, int);
void print(node *);
node* find(node *, int);
node* insrec(node *, int);
void del(node *, int);
int max(int a, int b)
{
	return (a>b)?a:b;
}

int main()
{
	int size;
	int i, inp;
	printf("Enter the no. of elements: ");
	scanf("%d", &size);
	for(i=0; i<size; i++){
		scanf("%d", &inp);
		root=insrec(root, inp);
		print(root);
		printf("\n");
	}
	printf("Height: %d\n", height(root));
/*	for(i=0; i<10; i++)
	{
		scanf("%d", &inp);
		node *search=find(root, inp);
		if(search)
			printf("Found %d\n", search->a);
		else
			printf("Not found\n");
	}
*/	
	for(i=0; i<10; i++)
	{
		scanf("%d", &inp);
		del(root, inp);
		print(root);
		printf("\n");
	}
	return 0;
}

//Iterative Insert in a BST
node* ins(node *root, int ip)
{
	node *new = (node *)malloc(sizeof(node));
	new->a=ip;
	new->left=NULL;
	new->right=NULL;
	if(root==NULL)
		root=new;
	else{
		node *temp=root, *parent=NULL;
		while(temp!=NULL)
		{
			parent=temp;
			if(temp->a > ip)
				temp=temp->left;
			else if(temp->a < ip)
				temp=temp->right;
		}
		if(parent->a > ip)
			parent->left=new;
		else if(parent->a < ip)
			parent->right=new;
	}
	return root;
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
		root=new;
		return root;
	}
	else
	{
		if(root->a < ip)
			root->right=insrec(root->right, ip);
		else if(root->a > ip)
			root->left=insrec(root->left, ip);
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
		printf("%d ", root->a);
		print(root->right);
	}
}

//Recursive Height Calculation of Binary Tree
int height(node *root)
{
	if(root==NULL) return -1;
	if(root->left==NULL && root->right==NULL)
		return 0;
	else
		return 1+max(height(root->left), height(root->right));
}

void del(node *root, int val)
{
	node *temp=root, *parent=NULL;
	int mode=-1;
	if(root->a == val) printf("Found root %d\n", root->a);
	else{
		while(temp->left!=NULL || temp->right!=NULL)
		{
			if((temp->left!=NULL && temp->left->a == val) || (temp->right!=NULL && temp->right->a == val))
				break;
			if(temp->a < val){
				temp=temp->right;
				if(temp==NULL) break;
			}
			else if(temp->a > val){
				temp=temp->left;
				if(temp==NULL) break;
			}
		}
		if(temp==NULL) printf("Not Found\n");
		else if(temp->left!=NULL && temp->left->a == val){
			printf("Found left %d\n", temp->left->a);
			parent=temp;
			temp=temp->left;
			mode=0;
		}
		else if(temp->right!=NULL && temp->right->a == val){
			printf("Found right %d\n", temp->right->a);
			parent=temp;
			temp=temp->right;
			mode=1;
		}
	}
	if(temp->right==NULL && temp->left==NULL)
	{
		if(mode==0)
		{
			parent->left=NULL;
			free(temp);
		}
		else if(mode==1)
		{
			parent->right=NULL;
			free(temp);
		}
	}
	else if(temp->right==NULL && temp->left!=NULL)
	{
		if(mode==0)
			parent->left=temp->left;
		else if(mode == 1)
			parent->right=temp->left;
		free(temp);
	}
	else if(temp->right!=NULL && temp->left==NULL)
	{
		if(mode==0)
			parent->left=temp->right;
		else if(mode == 1)
			parent->right=temp->right;
		free(temp);
	}
	else if(temp->right!=NULL && temp->left!=NULL)
	{
		node *head=temp->right;
		if(head->left != NULL){
			while(head->left->left!=NULL)
				head=head->left;
			temp->a=head->left->a;
			free(head->left);
			head->left=NULL;
		}
		else{
			temp->a=head->a;
			temp->right=NULL;
			free(head);
		}
	}
}
