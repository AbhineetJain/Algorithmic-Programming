#include<stdio.h>
#include<stdlib.h>

void print(int *, int);
int main()
{
	int tc, i, j, k, l;
	int n;
	int *arr;
	int limit;
	scanf("%d", &tc);
	for(i=0; i<tc; i++)
	{
		scanf("%d", &n);
		arr=(int *)calloc(n,sizeof(int));
		for(j=1, k=1; k<n;k++ ){
			arr[j]=k;
			limit=(k+2)%(n-k);
			if(limit==0) limit=(n-k);
	//		printf("n-k: %d lim: %d\n", n-k, limit);
			for(l=0; l<limit; l++){
				j+=1;
				j=j%n;
				if(arr[j]!=0)
					l--;
	//			printf("%d %d\n",k, l);
			}
	//		printf("j:%d\n", j);
	//		print(arr,n);
		}
	//	printf("%d\n", j);
		arr[j]=n;	
		print(arr, n);
	}
	return 0;
}

void print(int *arr, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d%s", arr[i], (i==n-1)?"\n":" ");
	
}
