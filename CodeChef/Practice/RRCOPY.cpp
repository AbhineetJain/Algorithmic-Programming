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
	VI array(100005);
	VI check(100005, 0);
	while(tc--)
	{
		SI(n);
		int count = 0;
		for(int i=0; i<n; i++)
		{
			SI(array[i]);
			if(check[array[i]] == 0)
			{
				check[array[i]] += 1;
				count++;
			}
		}
		printf("%d\n", count);
		for(int i=0; i<100005; i++)
			check[i] = 0;
	}
	return 0;
}
