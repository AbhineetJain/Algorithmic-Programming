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
	LL n, l, ind;
	cin >> n >> l;
	VLL lanterns;
	for(int i=0; i<n; i++)
	{
		cin >> ind;
		lanterns.pb(ind);
	}
	sortv(lanterns);
	double maxdiff = 0;
	for(int i=1; i<n; i++)
	{
		if(lanterns[i] - lanterns[i-1] > maxdiff)
			maxdiff = lanterns[i] - lanterns[i-1];
	}
	if(2*lanterns[0] > maxdiff)
		maxdiff = 2*lanterns[0];
	if(2*(l - lanterns[n-1]) > maxdiff)
		maxdiff = 2*(l - lanterns[n-1]);
	printf("%.9lf\n", maxdiff/2);
	return 0;
}
