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

bool comp(float i, float j)
{
	return i>j;
}

int main()
{
	int tc, denom_no, scenario_no;
	float denom[55];
	SI(tc);
	for(int i=0; i<tc; i++)
	{
		printf("Case %d:\n", i+1);
		SI(denom_no); SI(scenario_no);
		for(int j=0; j<denom_no; j++)
			scanf("%f", &denom[j]);
		sort(denom, denom + denom_no, comp);
		float amount;
		for(int j=0; j<scenario_no; j++)
		{
			printf("Scenario %d:\n", j+1);
			scanf("%f", &amount);
			for(int k=0; k<denom_no; k++)
			{
				int num = (int)(amount/denom[k]);
				if(num != 0)
				{
					if(denom[k] < 1)
						printf("%.2f %d\n", denom[k], num);
					else
						printf("%.0f %d\n", denom[k], num);
					amount -= (num*denom[k]);
				}
			}
		}
	}
	return 0;
}

