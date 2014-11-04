#include<stdio.h>
#define MAXSIZE 10000

void backshift(int a[], long long int n, long long int x, long long int k);
void forwardshift(int a[], long long int n, long long int x, long long int k);

int main()
{
	long long int i, j, k, T, n, x;
	int a[MAXSIZE]={0};
	scanf("%lld", &T);
	for(i=0; i<T; i++)
	{
	 	scanf("%lld %lld", &n, &x);
		for(j=0; a[j-1]!=-1; j++)
		{
			scanf("%lld", &a[j]);
		}
		for(k=0; k<j-1; k+=(n*2))
		{
			backshift(a,n,x,k);
		}
		for(k=n; k<j-1; k+=(n*2))
		{
			forwardshift(a,n,x,k);
		}
		for(k=0; k<j-1; k++)
		{
			printf("%c", a[k]);
		}
		printf("\n");
	}
	return 0;
}

void backshift(int a[], long long int n, long long int x, long long int k)
{
	int i;
	for(i=k; i<k+n; i++)
	{
		if(a[i]==-1)
			break;
		else if(a[i]>=97)
		{
			a[i]-=(x%26);
			if(a[i]<97)
				a[i]+=26;
		}
		else if(a[i]<=90)
		{
			a[i]-=(x%26);
			if(a[i]<65)
				a[i]+=26;
		}
	}
}

void forwardshift(int a[], long long int n, long long int x, long long int k)
{
	int i;
	for(i=k; i<k+n; i++)
	{
		if(a[i]==-1)
			break;
		else if(a[i]>=97)
		{
			a[i]+=(x%26);
			if(a[i]>122)
				a[i]-=26;
		}
		else if(a[i]<=90)
		{
			a[i]+=(x%26);
			if(a[i]>90)
				a[i]-=26;
		}
	}
}
