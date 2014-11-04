#include<stdio.h>

int ones(int n);

int main()
{
	int tc, i;
	int n;
	scanf("%d", &tc);
	for(i=0; i<tc; i++)
	{
		scanf("%d", &n);
		if(ones(n)==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

int ones(int n)
{
	int count=0;
	while(n>0)
	{
		if(n&01)
			count++;
		if(count>1)
			break;
		n=n>>1;
	}
	return count;
}
