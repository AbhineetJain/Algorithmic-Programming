#include<stdio.h>

int main()
{
	long long int n, T, i, sum=0;
	scanf("%lld", &T);
	for(i=0; i<T; i++)
	{
		scanf("%lld", &n);
		sum=(81*(n/9))+((n%9)*(n%9));
		printf("%lld\n", sum);
	}
	return 0;
}
