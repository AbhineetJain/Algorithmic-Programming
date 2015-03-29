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
	LL tc, n, k;
	SLL(tc);
	VLL removed(100005);
	VLL sumr(100005);
	while(tc--)
	{
		SLL(n); SLL(k);
		removed[0] = 0;
		for(int i=1; i<=k; i++)
			SLL(removed[i]);
		sort(removed.begin(), removed.begin()+k+1);
		sumr[0] = 0;
		for(int i=1; i<=k; i++)
			sumr[i] = sumr[i-1] + removed[i];
		LL step=(n*(n+1))/2 - sumr[k] + 1;
		for(int i=1; i<=k; i++)
		{
			if((removed[i]*(removed[i]+1)/2)-sumr[i] < removed[i])
			{
				step = removed[i];
				break;
			}
		}
//		printf("%lld\n", step);
		if(step%2==1)
			printf("Chef\n");
		else
			printf("Mom\n");
	}
	return 0;
}
