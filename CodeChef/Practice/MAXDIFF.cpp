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
	LL tc, n, k, arr[105];
	SLL(tc);
	while(tc--)
	{
		SLL(n);
		SLL(k);
		for(int i=0; i<n; i++)
			SLL(arr[i]);
		sort(arr, arr+n);
		if(k>n/2) k=n-k;
		int i;
		LL sum1=0, sum2=0;
		for(i=0; i<k; i++)
			sum1+=arr[i];
		for(;i<n;i++)
			sum2+=arr[i];
		printf("%lld\n", sum2-sum1);
	}
	return 0;
}
