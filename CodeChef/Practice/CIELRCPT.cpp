#include<bits/stdc++.h>

long long int count=0;

void rec_func(long long int n)
{
	int i=1;
	if(n==0)
		return;
	else{
		while(i<12 && 1<<i <= n)
			i++;
		count++;
		rec_func(n-(1<<(i-1)));
	}
}
int main()
{
	long long int tc, n;
	scanf("%lld", &tc);
	while(tc--)
	{
		count=0;
		scanf("%lld", &n);
		rec_func(n);
		printf("%lld\n", count);
	}
	return 0;
}
