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
	int n, k, val;
	SI(n);
	SI(k);
	int count=0;
	for(int i=0; i<n; i++)
	{
		SI(val);
		if(val%k==0)
			count++;
	}
	printf("%d\n", count);
	return 0;
}
