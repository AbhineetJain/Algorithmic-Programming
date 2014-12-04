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
	LL n, k;
	SI(tc);
	while(tc--)
	{
		SLL(n); SLL(k);
		if(k != 0)
			cout << n/k << " " << n%k << endl;
		else
			cout << "0" << " " << n << endl;
	}
	return 0;
}
