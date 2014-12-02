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
	int tc;
	int n, r, R;
	SI(tc);
	vector<pair<int, int> > cones(501);
	while(tc--)
	{
		SI(r); SI(R); SI(n);
		int x, y;
		for(int i=0; i<n; i++)
		{	
			SI(x);
			SI(y);
			cones[i] = mp(x, y);
			printf("%lf", max(sqrt(x*x+y*y) - r, R - sqrt(x*x+y*y)));
		}
		

	}
	return 0;
}
