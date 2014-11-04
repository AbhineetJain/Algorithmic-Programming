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
	int pies[35], racks[35];
	SI(tc);
	while(tc--)
	{
		SI(n);
		for(int i=0; i<n; i++)
			SI(pies[i]);
		for(int i=0; i<n; i++)
			SI(racks[i]);
		sort(pies, pies+n);
		sort(racks, racks+n);
		int count=0;
		for(int i=0, j=0; i<n && j<n; )
		{
			if(pies[i]<=racks[j])
			{
				i++; j++;
			}
			else
			{
				j++;
				count++;
			}
		}
		printf("%d\n", n-count);
	}
	return 0;
}
