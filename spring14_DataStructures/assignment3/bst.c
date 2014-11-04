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
node *prev=NULL;
node *foundnode=NULL;
node *kmin = NULL;
int mincount=0;

void print(node *);
node* find(node *, int);
node* insrec(node *, int);
void printlevel(node *, node *);
void printkmin(node *, int);

int main()
{
	int tc;
	int j;
	scanf("%d", &tc);
	for(j=0; j<tc; j++){
		int size;
		root=NULL;
		prev=NULL;
		foundnode=NULL;
		kmin = NULL;
		mincount=0;
		int i, inp;
		scanf("%d", &size);
		for(i=0; i<size; i++){
			scanf("%d", &inp);
			root=insrec(root, inp);
			root->level = 0;
		}
		int mynode, k;
		scanf("%d%d", &mynode, &k);
		node* findlevel=find(root, mynode);
		if(findlevel == NULL) printf("$ $");
		else{
		printlevel(root, findlevel);
		if(foundnode == NULL) printf("$ $");
		else{
			printf("%d ", foundnode->a);
			printkmin(foundnode, k);
			if(kmin!=NULL)
				printf("%d", kmin->a);
			else
				printf("$");
		}
		}
		printf("\n");
	}
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
		root=new;
		return root;
	}
	else
	{
		if(root->a < ip){
			root->right=insrec(root->right, ip);
			root->right->level = root->level + 1;
		}
		else if(root->a > ip){
			root->left=insrec(root->left, ip);
			root->left->level = root->level + 1;
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
		printf("%d(%d) ", root->a, root->level);
		print(root->right);
	}
}

void printlevel(node *root, node *findlevel)
{
	if(root!=NULL)
	{
		printlevel(root->left, findlevel);
		if(root->level == findlevel->level){
			if(prev == NULL) prev = root;
			else {
				if(prev->a == findlevel->a)
				{
					if(foundnode == NULL)
						foundnode = root;
					return;
				}
				else
					prev = root;
			}
		}
		printlevel(root->right, findlevel);
	}
	return;
}

void printkmin(node *root, int k)
{
	if(root!=NULL){
		printkmin(root->left, k);
		mincount++;
		if(mincount == k){ if(kmin==NULL) kmin = root; return; }
		printkmin(root->right, k);
	}
}
