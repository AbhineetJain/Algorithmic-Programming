#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VI;
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
	LL n, m, k, inp, count=0;
	SLL(n); SLL(m); SLL(k);
	LL pos[100005];
	LL app[100005];
	for(LL i=1; i<=n; i++)
	{
		SLL(app[i]);
		pos[app[i]] = i;
	}
	for(LL i=0; i<m; i++)
	{
		SLL(inp);
		count += ((pos[inp]-1)/k + 1);
		if(pos[inp] != 1)
		{
			app[pos[inp]] = app[pos[inp]] + app[pos[inp]-1] - (app[pos[inp]-1] = app[pos[inp]]);
			pos[inp] = pos[inp] - 1;
			pos[app[pos[inp]+1]] = pos[inp] + 1;
		}
	}
	cout << count << endl;
	return 0;
}
