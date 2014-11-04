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
	LL tc;
	LL notes, cost;
	SLL(tc);
	LL money[105];
	while(tc--)
	{
		SLL(notes); SLL(cost);
		LL total=0;
		for(int i=0; i<notes; i++)
		{
			SLL(money[i]);
			total+=money[i];
		}
		LL remainder = total%cost;
		LL flag=0;
		for(int i=0; i<notes; i++)
		{
			if(money[i]<=remainder)
			{
				flag=1;
				break;
			}
		}
		if(flag)
			printf("-1\n");
		else
			printf("%lld\n", total/cost);
	}
	return 0;
}
