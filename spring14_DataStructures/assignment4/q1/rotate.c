#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node *left;
	struct node *right;
};
typedef struct node node;

node *root=NULL;
int *array=NULL;
int counter = 0;

node* insrec(node *, int);
node* newroot(node *, int);
node* find(node *, int);
node* singleleft(node *);
node* singleright(node *);
void  preOrder(node *);
void  postOrder(node *);
void  inOrder(node *);
void  printArray(int *arr, int size)
{
	int i;
	for(i=0; i<size-1; i++)
		printf("%d ", arr[i]);
	printf("%d\n", arr[i]);
}

int main()
{
	int testCases, i, j, size, newRoot, inpVal;
	scanf("%d", &testCases);
	for(i=0; i<testCases; i++)
	{
		root=NULL;
		array=NULL;
		scanf("%d", &size);
		array = (int *)malloc(sizeof(int)*size);
		for(j=0; j<size; j++)
		{
			scanf("%d", &inpVal);
			root=insrec(root, inpVal);
		//	postOrder(root);
		//	printf("\n");
		}
		for(j=0; j<size; j++)
			scanf("%d", &inpVal);
		scanf("%d", &newRoot);
		//printf("%d\n", newRoot);
		while(root->value != newRoot) {
			root=find(root, newRoot);
		}
		counter = 0;
		inOrder(root);
		printArray(array, size);
		counter = 0;
		preOrder(root);
		printArray(array, size);
		counter = 0;
		postOrder(root);
		printArray(array, size);
	}
	return 0;
}

node* insrec(node *root, int ip)
{
	if(root==NULL)
	{
		node *new=(node *)malloc(sizeof(node));
		new->value=ip;
		new->left=NULL;
		new->right=NULL;
		root=new;
		return root;
	}
	else
	{
		if(root->value < ip){
			root->right=insrec(root->right, ip);
		}
		else if(root->value > ip){
			root->left=insrec(root->left, ip);
		}
	}
	return root;
}

node* newroot(node *root, int newRoot)
{
	node *findParent = find(root, newRoot);
	if(findParent->left->value == newRoot)
		findParent = singleleft(findParent);
	else if(findParent->right->value == newRoot)
		findParent = singleright(findParent);
	printf("%d %d\n", findParent->value, findParent->right->value);
	return root;
}

node* find(node *root, int val)
{
	if(root!=NULL)
	{
		if(root->left!=NULL && root->left->value == val)
			return singleleft(root);
		else if(root->right!=NULL && root->right->value == val)
			return singleright(root);
		else {	
			if(root->value > val){
				root->left=find(root->left, val);
			}
			else if(root->value < val){
				root->right=find(root->right, val);
		//		printf("%d\n", root->right->value);
			}
		}
	}
	return root;
}

node* singleleft(node *root)
{
	node *temp;
	temp=root->left;
	root->left=temp->right;
	temp->right=root;
	return temp;
}

node* singleright(node *root)
{
	node *temp;
	temp=root->right;
	root->right=temp->left;
//	printf("%d\n", root->right->value);
	temp->left=root;
	return temp;
}

void preOrder(node *root)
{
	if(root!=NULL)
	{
		array[counter++] = root->value;
		//printf("%d ", root->value);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(node *root)
{
	if(root!=NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		array[counter++] = root->value;
		//printf("%d ", root->value);
	}
}

void inOrder(node *root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		array[counter++] = root->value;
		//printf("%d ", root->value);
		inOrder(root->right);
	}
}
