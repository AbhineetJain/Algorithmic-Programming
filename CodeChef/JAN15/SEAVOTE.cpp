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
	SI(tc);
	int n, val;
	while(tc--)
	{
		SI(n);
		int sum = 0;
		for(int i=0; i<n; i++)
		{
			SI(val);
			if(val == 0)
			{
				n--;
				i--;
			}
			sum += val;
		}
		if(sum >= 100 && sum <= 100+n-1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
