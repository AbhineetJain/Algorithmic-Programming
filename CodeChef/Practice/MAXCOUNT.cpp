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
	int tc, n, arr[105], count[10005];
	SI(tc);
	while(tc--)
	{
		int max=0, index;
		for(int i=0; i<10005; i++)
			count[i]=0;
		SI(n);
		for(int i=0; i<n; i++)
		{
			SI(arr[i]);
			count[arr[i]]++;
		}
		for(int i=0; i<10005; i++)
		{
			if(count[i]>max)
			{
				max=count[i];
				index=i;
			}
		}
		printf("%d %d\n", index, max);
	}
	return 0;
}
