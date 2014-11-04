#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

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
	int tc, n;
	SI(tc);
	int ing[55];
	while(tc--)
	{
		SI(n);
		for(int i=0; i<n; i++)
			SI(ing[i]);
		int g=gcd(ing[0], ing[1]);
		for(int i=2; i<n; i++)
		{
			if(g==1)
				break;
			else
				g=gcd(g,ing[i]);
		}
		for(int i=0; i<n; i++)
			printf("%d ", ing[i]/g);
		printf("\n");
	}
	return 0;
}
