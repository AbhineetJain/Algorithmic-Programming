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
	int tc, n, count, val;
	SI(tc);
	VI distinct(100005, 0);
	while(tc--)
	{
		SI(n);
		count = 0;
		for(int i = 0; i < 100005; i++)
			distinct[i] = 0;
		for(int i = 0; i < n; i++)
		{
			SI(val);
			if(!distinct[val])
			{
				count++;
				distinct[val] = 1;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
