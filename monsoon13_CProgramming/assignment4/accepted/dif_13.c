#include<stdio.h>
#define num 1000000007

int  mypow(int a, int b)
{
	if(b==0)
		return 1;
	long long int c=mypow(a,b/2);
	c=(c*c)%num;
	if(!(b&1))
		return c;
	else
		return (a*c)%num;
}

int main()
{
	int a, b;
	int tc, i;
	scanf("%d", &tc);
	for(i=0; i<tc; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", mypow(a,b));
	}
	return 0;
}
