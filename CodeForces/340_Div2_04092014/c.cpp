#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b)
{
	long long int temp;
	while(b)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}

int main()
{
	long long int n;
	int i;
	scanf("%lld", &n);
	long long int *array = (long long int *)malloc(sizeof(long long int)*n);
	for(i=0; i<n; i++)
		scanf("%lld", &array[i]);
	sort(array, array+n);
	long long int sum=0;
	for(i=0; i<n; i++)
	{
		sum+=2*(array[i]*i - array[i]*(n-i-1));
		sum+=array[i];
	}
	long long int gcdAns = gcd(sum, n);
	printf("%lld %lld\n", sum/gcdAns, n/gcdAns);
	return 0;
}

