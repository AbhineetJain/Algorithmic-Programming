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
	while(tc--)
	{
		int n, m;
		SI(n); SI(m);
		int heights[105];
		for(int i=0; i<n; i++)
			SI(heights[i]);
		sort(heights, heights+n);
		int max=heights[n-1];
		int i;
		for(i=0; i<n-1; i++)
		{
			m-=(max-heights[i]);
			heights[i]+=(max-heights[i]);
			if(m<0)
				break;
		}
		if(i==n-1)
		{
			if(m%n==0 && m>=0)
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			printf("No\n");
	}
	return 0;
}
