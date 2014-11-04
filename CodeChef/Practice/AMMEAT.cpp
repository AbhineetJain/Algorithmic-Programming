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
	LL tc, n, m;
	SLL(tc);
	while(tc--)
	{
		SLL(n); SLL(m);
		VLL pies;
		LL input;
		for(int i=0; i<n; i++)
		{
			SLL(input);
			pies.pb(input);
		}
		sortv(pies);
		reverse(pies.begin(), pies.end());
		LL total = 0;
		int i;
		for(i=0; i<n; i++)
		{
			total+=pies[i];
			if(total>=m)
				break;
		}
		if(i==n)
			printf("-1\n");
		else
			printf("%d\n", i+1);
	}
	return 0;
}
