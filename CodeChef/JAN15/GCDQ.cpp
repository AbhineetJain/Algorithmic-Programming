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
	int n, q, l, r;
	SI(tc);
	int arr[100010], prefix[100010];
	int suffix[100010];
	while(tc--)
	{
		SI(n); SI(q);
		for(int i=0; i<n; i++)
			SI(arr[i]);
		prefix[0] = arr[0];
		suffix[n-1] = arr[n-1];
		for(int i=1; i<n; i++)
		{
			prefix[i] = __gcd(prefix[i-1], arr[i]);
			suffix[n-1-i] = __gcd(suffix[n-i], arr[n-1-i]);
		}
		for(int i=0; i<q; i++)
		{
			SI(l); SI(r);
			l--; r--;
			if(l==0)
				printf("%d\n", suffix[r+1]);
			else if(r==n-1)
				printf("%d\n", prefix[l-1]);
			else
				printf("%d\n", __gcd(suffix[r+1], prefix[l-1]));
		}
	}
	return 0;
}
