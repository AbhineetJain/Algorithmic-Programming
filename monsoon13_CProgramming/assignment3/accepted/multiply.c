#include<stdio.h>

int input(int arr[1010], int *b);
void init_arr(int a[10000], int l);
void printarr(int a[10000], int l);
void revarr(int a[10000], int l);

int main()
{
	int t, i=0, j, k, l;
	int arr1[1010], arr2[1010];
	int arrans[10000];
	int neg1=0, neg2=0;
	int c, l1, l2, product;
	scanf("%d", &t);
	getchar();
	for(i=0; i<t; i++)
	{
	  init_arr(arr1, 1010);
	  init_arr(arr2, 1010);
	  init_arr(arrans, 10000);
	  neg1=neg2=0;
	  l1=input(arr1, &neg1);
	  l2=input(arr2, &neg2);
	  for(j=l1-1; j>=0; j--)
	  {
		  for(k=l2-1, l=l1-j-1; k>=0; l++, k--)
		  {
				product=arr1[j]*arr2[k];
				arrans[l]+=product;
				arrans[l+1]+=(arrans[l]/10);
				arrans[l]%=10;
		  }
	  }
	  if(arrans[l]>0)
		  l=l+1;
	  revarr(arrans, l);
	  if(neg1!=neg2)
		  putchar('-');
	  printarr(arrans, l);
	}
	return 0;
}

int input(int arr[1010], int *b)
{
	int c;
	int i=0;
	while((c=getchar())!='\n')
	{
		if(c=='-')
			*b=1;
		else
		{
			arr[i]=c-'0';
			i++;
		}
	}
	return i;
}

void init_arr(int a[10000], int l)
{
	int i;
	for(i=0; i<l; i++)
		a[i]=0;
}

void printarr(int a[1010], int l)
{
	int i;
	for(i=0; i<l; i++)
		printf("%d", a[i]);
	printf("\n");
}

void revarr(int a[1010], int l)
{
	int i,j;
	for(i=0, j=l-1; i<j; i++, j--)
	{
		a[j]=a[i]+a[j]-(a[i]=a[j]);
	}
}
