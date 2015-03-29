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
	LL n, m, val, total = 0, func, factval;
	VLL fact;
	SLL(n); SLL(m);
	fact.resize(m);
	fact[0] = 1%m;
	fact[1] = 1%m;
	for(int i=2; i<m; i++)
		fact[i] = (fact[i-1]*i)%m;
	for(int i=0; i<n; i++)
	{
		SLL(val);
		if(val >= m-1) factval = 0;
		else factval = fact[val+1];
		func = (((((val%m)*(val%m)%m)*((val%m + 1)%m)/2)%m) + ((factval - 1)%m))%m;
		total = (total + func)%m;
	}
	cout << total << endl;
	return 0;
}
