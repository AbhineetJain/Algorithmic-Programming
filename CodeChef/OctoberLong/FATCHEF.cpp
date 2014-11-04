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
		vector<pair<LL,char> > buckets(100005);
		SLL(n); SLL(m);
		getchar();
		for(int i=0; i<m; i++)
		{
			scanf("%c", &buckets[i].s); SLL(buckets[i].f); getchar();
		}
		sort(buckets.begin(), buckets.begin()+m);
		LL ans=1;
		for(int i=0; i<m-1; i++)
		{
			if(buckets[i+1].s != buckets[i].s)
				ans=(ans*(buckets[i+1].f-buckets[i].f))%(LL)(1e9+9);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
