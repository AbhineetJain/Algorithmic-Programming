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

long long modFast(long long n, long long p)
{
	long long res = 1;
	while (n > 0)
	{
		for (long long i = 1, m = n % p; i <= m; i++)
			res = (res * i) % p;
		if ((n /= p) % 2)
			res = p - res;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, p;
	cin >> n >> p;
	cout << modFast(n, p) << endl;
	return 0;
}
