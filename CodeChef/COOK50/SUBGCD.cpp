#include<bits/stdc++.h>

int gcd(int a, int b)
{
	int c;
	while(b)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int main()
{
	long long int arr[100005];
	long long int n;
	long long int tc;
	long long int k;
	scanf("%lld", &tc);
	while(tc--)
	{
		scanf("%lld", &n);
		for(int i=0; i<n; i++)
			scanf("%lld", &arr[i]);
		k=gcd(arr[0], arr[1]);
		for(int i=2; i<n-1; i++)
			k=gcd(k, arr[i]);
		if(k==1)
			printf("%lld\n", n);
		else
			printf("-1\n");
	}
	return 0;
}
