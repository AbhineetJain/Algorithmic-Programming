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
	LL tc, n, min=1e9, diff;
	LL horses[5005];
	SLL(tc);
	while(tc--)
	{
		min=1e9;
		SLL(n);
		for(int i=0; i<n; i++)
			SLL(horses[i]);
		sort(horses, horses+n);
		for(int i=0; i<n-1; i++)
		{
			diff=horses[i+1]-horses[i];
			if(diff<min)
				min=diff;
		}
		printf("%lld\n", min);
	}
	return 0;
}
