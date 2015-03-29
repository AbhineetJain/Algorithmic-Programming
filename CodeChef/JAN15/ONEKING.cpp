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
	int tc, n;
	SI(tc);
	vector<pair<int, int> > kingdoms(100005);
	while(tc--)
	{
		SI(n);
		for(int i=0; i<n; i++)
		{
			SI(kingdoms[i].s);
			SI(kingdoms[i].f);
		}
		sort(kingdoms.begin(), kingdoms.begin()+n);
		int comp = kingdoms[0].f;
		int ans = 1;
		for(int i=1; i<n; i++)
		{
			if(kingdoms[i].s > comp)
			{
				comp = kingdoms[i].f;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
