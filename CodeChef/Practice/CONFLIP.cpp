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

int main()
{
	LL tc, g, start, n, final;
	SLL(tc);
	while(tc--)
	{
		SLL(g);
		for(int i=0; i<g; i++)
		{
			SLL(start); SLL(n); SLL(final);
			if(n%2)
			{
				if(start==final)
					printf("%lld\n", n/2);
				else
					printf("%lld\n", n/2+1);
			}
			else
				printf("%lld\n", n/2);
		}
	}
	return 0;
}
