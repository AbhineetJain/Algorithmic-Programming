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
	LL tc;
	LL a[100100], b[100100];
	SLL(tc);
	LL n, k;
	while(tc--)
	{
		SLL(n); SLL(k);
		for(int i=0; i<n; i++)
		{
			SLL(a[i]);
		}
		for(int i=0; i<n; i++)
		{
			SLL(b[i]);
		}
		LL maxi = 0;
		for(int i=0; i<n; i++)
		{
			maxi = max(maxi, (k/a[i])*b[i]);
		}
		printf("%lld\n", maxi);
	}
	return 0;
}
