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
	LL tc, n;
	int arr[100005], ans[100005];
	SLL(tc);
	while(tc--)
	{
		SLL(n);
		for(int i=0; i<n; i++)
			SI(arr[i]);
		sort(arr, arr+n);
		int i, j;
		for(i=0, j=0; i<n; i+=2)
		{
			ans[i]=arr[j++];
		}
		for(i=1; j<n; i+=2, j++)
			ans[i]=arr[j];
		for(i=0; i<n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}
