#include<stdio.h>
#include<stdlib.h>

struct node{
	int a;
	struct node *left;
	struct node *right;
	int height;
};
typedef struct node node;

node* insert(node *, int);
node* singleleft(node *);
node* singleright(node *);
node* doubleleft(node *);
node* doubleright(node *);
node* delete(node *, int);
int height(node *);
void print(node *);
int max(int a, int b)
{
	return (a>b)?a:b;
}

node *root=NULL;
int printarray[100000];
int length=0;

int main()
{
	int tc, i, j, ip, nq;
	char opt;
	scanf("%d", &tc);
//	printf("%d\n", tc);
	for(i=0; i<tc; i++)
	{
		root=NULL;
		scanf("%d", &nq);
//		printf("i:%d nq:%d\n", i, nq);
		for(j=0; j<nq; j++)
		{
			opt=getchar();
			if(opt==10||opt==32) j--;
//			printf("j:%d opt:%d\n", j, opt);
			switch(opt){
				case 'i':	scanf("%d", &ip);
						root=insert(root, ip);
						//print(root);
						//printf("\n");
						break;

				case 'd':	scanf("%d", &ip);
						root=delete(root, ip);
						break;

				case 'p':	length=0;
						print(root);
						int k;
						for(k=0; k<length-1; k++)
							printf("%d ", printarray[k]);
						if(length>0) printf("%d", printarray[k]);
						printf("\n");
						break;
			}
		}
	}
	return 0;
}

node* insert(node *root, int val)
{
	if(root==NULL)
	{
		root=(node *)malloc(sizeof(node));
		root->a=val;
		root->height=0;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		if(val < root->a){
			root->left=insert(root->left, val);
			if(height(root->left)-height(root->right) == 2)
			{
				if(val < root->left->a)
					root = singleleft(root);
				else
					root = doubleleft(root);
			}
		}
		else if(val > root->a){
			root->right=insert(root->right, val);
			if(height(root->right)-height(root->left) == 2)
			{
				if(val > root->right->a)
					root = singleright(root);
				else
					root = doubleright(root);
			}
		}
	}
	root->height = 1 + max(height(root->left), height(root->right));
	return root;
}

node* delete(node *root, int val)
{
	if(root==NULL)
		return root;
	if(root->a > val)
		root->left=delete(root->left, val);
	else if(root->a < val)
		root->right=delete(root->right, val);
	else
	{
		if(root->left == NULL || root->right == NULL)
		{
			node *temp = root->left?root->left:root->right;
			if(temp==NULL){
				temp=root;
				root=NULL;
			}
			else
				*root=*temp;
			free(temp);
		}
		else
		{
			node *temp=root->right;
			while(temp->left!=NULL)
				temp=temp->left;
			root->a=temp->a;
			root->right=delete(root->right, temp->a);
		}
	}
	if(root==NULL)
		return root;
	root->height = 1+max(height(root->left), height(root->right));
	if(height(root->left)-height(root->right) >= 2)
	{
		if(height(root->left->left) >= height(root->left->right))
			root = singleleft(root);
		else
			root = doubleleft(root);
	}
	if(height(root->right)-height(root->left) >= 2)
	{
		if(height(root->right->right) >= height(root->right->left))
			root = singleright(root);
		else
			root = doubleright(root);
	}
	return root;
}

node* singleleft(node *root)
{
	node *temp;
	temp=root->left;
	root->left=temp->right;
	temp->right=root;
	root->height=1+max(height(root->left), height(root->right));
	temp->height=1+max(height(temp->left), root->height);
	return temp;
}

node* singleright(node *root)
{
	node *temp;
	temp=root->right;
	root->right=temp->left;
	temp->left=root;
	root->height=1+max(height(root->left), height(root->right));
	temp->height=1+max(root->height, height(temp->right));
	return temp;
}

node* doubleleft(node *root)
{
	root->left=singleright(root->left);
	return singleleft(root);
}

node* doubleright(node *root)
{
	root->right=singleleft(root->right);
	return singleright(root);
}

int height(node *root)
{
	if(root==NULL)
		return -1;
	else
		return root->height;
}

void print(node *root)
{
	if(root!=NULL){
//		printf("%d(%d) ", root->a, root->height);
		//printf("%d ", root->a);
		printarray[length++]=root->a;
		print(root->left);
		print(root->right);
	}
}
