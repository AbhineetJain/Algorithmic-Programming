#include<stdio.h>
#define num 1000000007

int m[1000][1000];

int c(int n, int r)
{
	if(m[n-1][r]!=-1)
		return m[n-1][r];
	if(r==0 || r==n)
		return 1;
	else if(r==1 || r==n-1)
		return n;	
	else{
		return m[n-1][r]=(c(n-1,r)+c(n-1,r-1))%num;
	}
}

int  main()
{
	int tc, i;
	int n, r;
	int j, k;
	scanf("%d", &tc);
	for(j=0; j<1000; j++){
		m[j][0]=1;
		m[j][1]=j+1;
	}
	for(j=0; j<1000; j++)
	{
		for(k=2; k<1000; k++)
			m[j][k]=-1;
	}
	for(i=0; i<tc; i++)
	{
		scanf("%d %d", &n, &r);
		printf("%d\n", c(n,r));
	}
	return 0;
}
