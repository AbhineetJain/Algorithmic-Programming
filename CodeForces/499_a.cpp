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
	int n, x;
	SI(n); SI(x);
	LL ans = 0;
	pair<int, int> times[55];
	for(int i=0; i<n; i++)
	{
		SI(times[i].f); SI(times[i].s);
		ans += (times[i].s - times[i].f + 1);
	}
//	cout << ans << endl;
//	sort(times, times+n);
	ans += ((times[0].f - 1)%x);
//	cout << ans << endl;
	for(int i=1; i<n; i++)
	{
		ans += (times[i].f - times[i-1].s - 1)%x;
//		cout << ans << endl;
	}
	printf("%lld\n", ans);
	return 0;
}
