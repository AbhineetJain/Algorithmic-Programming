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

VI array(100005);
VI dpMCS(100005, -1);

int maxcontsubarray(int n)
{
	if(dpMCS[n] != -1)
		return dpMCS[n];
	else if(n == 0)
		return dpMCS[0] = array[0];
	else
	{
		return dpMCS[n] = max(maxcontsubarray(n-1), maxcontsubarray(n-1)+array[n]);
	}
}

int main()
{
	int tc;
	int n;
	SI(tc);
	while(tc--)
	{
		SI(n);
		for(int i=0; i<n; i++)
		{
			SI(array[i]);
			dpMCS[i] = -1;
		}
		printf("%d\n", maxcontsubarray(n-1));
	}
	return 0;
}
