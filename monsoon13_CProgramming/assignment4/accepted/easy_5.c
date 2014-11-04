#include<stdio.h>

void create(int a[][100], int size);
int knightattack(int a[][100], int size);

int main()
{
	int size;
	scanf("%d", &size);
	int board[size+5][size+5];
	create(board, size);
	int attack= knightattack(board, size);
	if(attack)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

void create(int a[][100], int size)
{
	int i, j;
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
			scanf("%d", &a[i][j]);
	}
}

int knightattack(int a[][100], int size)
{
	int i, j, k, l, m, n;
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		{
			if(a[i][j]==1){
			for(k=i,m=0; (k>0&&m!=2);m++)
				k--;
			for(l=j,n=0; (l>0&&n!=1);n++)
				l--;
			if(a[k][l]==1&&m==2&&n==1)
			{
			//	printf("%d,%d\n", i, j);
			//	printf("Exit1\n");
				return 1;
			}
			if(l+2<size){if(a[k][l+2]==1&&m==2&&n==1){ /*printf("%d,%d\n", i, j); printf("Exit2\n");*/ return 1;}}
			for(k=i,m=0; (k<size&&m!=2);m++)
				k++;
			for(l=j,n=0; (l<size&&n!=1);n++)
				l++;
			if(a[k][l]==1&&m==2&&n==1)
			{
			//	printf("%d,%d\n", i, j);
			//	printf("Exit3\n");
				return 1;
			}
			if(l-2>=0){if(a[k][l-2]==1&&m==2&&n==1){ /*printf("%d,%d\n", i, j); printf("Exit4\n");*/ return 1; }}
			
			for(k=j,m=0; (k>0&&m!=2);m++)
				k--;
			for(l=i,n=0; (l>0&&n!=1);n++)
				l--;
			if(a[l][k]==1&&m==2&&n==1)
			{
			//	printf("%d,%d\n", i, j);
			//	printf("Exit5\n");
				return 1;
			}
			if(l+2<size){if(a[l+2][k]==1&&m==2&&n==1){ /*printf("%d,%d\n", i, j); printf("Exit6\n");*/ return 1;}}
			for(k=j,m=0; (k<size&&m!=2);m++)
				k++;
			for(l=i,n=0; (l<size&&n!=1);n++)
				l++;
			if(a[l][k]==1&&m==2&&n==1)
			{
			//	printf("%d,%d\n", i, j);
			//	printf("Exit7\n");
				return 1;
			}
			if(l-2>=0){if(a[l-2][k]==1&&m==2&&n==1){ /*printf("%d,%d\n", i, j); printf("Exit8\n");*/ return 1; }}
		}
		}
	}
	return 0;
}

			
			
