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
	int n, sum = 0;
	SI(n);
	int weights[110];
	for(int i=0; i<n; i++)
	{
		SI(weights[i]);
		sum+=weights[i];
	}
	if(sum%2 == 1)
		printf("NO\n");
	else
	{
		sort(weights, weights + n);
		int halfSum = 0, j = 0;
		while(halfSum < sum/2)
		{
			halfSum += weights[j];
		}
		if(halfSum == sum/2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
