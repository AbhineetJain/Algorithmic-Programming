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
	LL n1, n2, n3;
	scanf("%lld%lld%lld", &n1, &n2, &n3);
	VLL l1(n1), l2(n2), l3(n3), ans;
	for(int i=0; i<n1; i++)
		SLL(l1[i]);
	for(int i=0; i<n2; i++)
		SLL(l2[i]);
	for(int i=0; i<n3; i++)
		SLL(l3[i]);
	for(int i=0; i<n1; i++)
	{
		if(binary_search(l2.begin(), l2.end(), l1[i]))
		{
			ans.pb(l1[i]);
		}
		else if(binary_search(l3.begin(), l3.end(), l1[i]))
		{
			ans.pb(l1[i]);
		}
	}
	for(int i=0; i<n2; i++)
	{
		if(binary_search(l3.begin(), l3.end(), l2[i]))
		{
				ans.pb(l2[i]);
		}
	}
	sortv(ans);
	vector<long long int>::iterator it = unique(ans.begin(), ans.end());
	ans.resize(distance(ans.begin(), it));
	int l=ans.size();
	printf("%d\n", l);
	for(int i=0; i<l; i++)
		printf("%lld\n", ans[i]);
	return 0;
}
