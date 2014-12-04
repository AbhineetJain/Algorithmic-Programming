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
	int n;
	int array[100005];
	SI(tc);
	while(tc--)
	{
		SI(n);
		int ncs = 0;
		for(int i=0; i<n; i++)
		{
			SI(array[i]);
			if(array[i] > 0)
				ncs += array[i];
		}
		int  max_sum = 0, current_sum = 0;
		if(ncs != 0)
		{
			for(int i=0; i<n; i++)
			{
				if(current_sum + array[i] > 0)
					current_sum += array[i];
				else
					current_sum = 0;
				if(current_sum > max_sum)
					max_sum = current_sum;
			}
		}
		else
		{
			int maximum = array[0];
			for(int i=1; i<n; i++)
				maximum = max(maximum, array[i]);
			max_sum = ncs = maximum;
		}	
		printf("%d %d\n", max_sum, ncs);
	}
	return 0;
}
