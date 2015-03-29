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
	LL n;
	SLL(n);
	LL product = 1;
	LL numbers[100005];
	for(LL i = 0; i<n; i++)
	{
		SLL(numbers[i]);
		product *= numbers;
	}
	factorize(number);
	return 0;
}
