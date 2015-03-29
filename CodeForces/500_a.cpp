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
	int n, t;
	SI(n); SI(t);
	VI portal(n);
	int ans=1;
	for(int i=0; i<n-1; i++)
	{
		SI(portal[i]);
	}
	for(int i=0; i<n-1; )
	{
		ans += portal[i];
		i += portal[i];
//		printf("%d ", ans);
		if(ans == t)
		{
//			cout << endl;
			cout << "YES\n";
			return 0;
		}
	}
//	cout << endl;
	cout << "NO\n";
	return 0;
}
