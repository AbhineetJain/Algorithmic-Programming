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

LL dp[10005];
VLL scores(10005);

LL calScore(int index)
{
	if(index < 0)
		return 0;
	if(dp[index] != -1)
		return dp[index];
	return dp[index] = max(scores[index] + calScore(index-2), calScore(index-1));
}

int main()
{
	int tc, n;
	SI(tc);
	for(int j=0; j<tc; j++)
	{
		SI(n);
		for(int i=0; i<n; i++)
		{
			SLL(scores[i]);
			dp[i] = -1;
		}
		calScore(n-1);
		printf("Case %d: %lld\n", j+1, dp[n-1]);
	}
	return 0;
}
