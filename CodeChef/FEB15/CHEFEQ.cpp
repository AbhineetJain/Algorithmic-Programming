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
	SLL(tc);
	LL n, val, maxVal;
	while(tc--)
	{
		SLL(n);
		VI count(100005);
		maxVal = 0;
		for(int i=0; i<n; i++)
		{
			SLL(val);
			count[val]++;
			if(count[val] > maxVal)
				maxVal = count[val];
		}
		cout << n - maxVal << endl;
	}
	return 0;
}
