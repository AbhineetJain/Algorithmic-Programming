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
	LL n, q;
	SLL(n); SLL(q);
	LL query;
	for(int i=0; i<q; i++)
	{
		SLL(query);
		if(query < n + 2 || query > 3*n)
			printf("0\n");
		else if(query <= 2*n + 1)
			printf("%lld\n", query-n-1);
		else
			printf("%lld\n", 3*n - query + 1);
	}
	return 0;
}
