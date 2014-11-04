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
	LL n, arr[1000005];
	SLL(n);
	for(LL i=0; i<n; i++)
		SLL(arr[i]);
	sort(arr, arr+n);
	for(LL i=0; i<n; i++)
		printf("%lld\n", arr[i]);
	return 0;
}
