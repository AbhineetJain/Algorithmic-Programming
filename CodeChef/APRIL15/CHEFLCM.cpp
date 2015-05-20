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

LL sumoffactors(int val)
{
	LL sum = 0;

}

int main()
{
	int tc;
	int n, val;
	cin >> tc;
	while(tc--)
	{
		cin >> n >> val;
		cout << sumoffactors(val) << endl;
	}
	return 0;
}
