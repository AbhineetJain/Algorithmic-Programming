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
	LL tc, r, g, b, m;
	SLL(tc);
	while(tc--)
	{
		SLL(r); SLL(g); SLL(b); SLL(m);
		LL maxR=0, maxG=0, maxB=0, inp;
		for(int i=0; i<r; i++)
		{
			SLL(inp);
			if(inp>maxR)
				maxR=inp;
		}
		for(int i=0; i<g; i++)
		{
			SLL(inp);
			if(inp>maxG)
				maxG=inp;
		}
		for(int i=0; i<b; i++)
		{
			SLL(inp);
			if(inp>maxB)
				maxB=inp;
		}
		LL maxArr[4]={maxR, maxG, maxB};
		LL minVol=(LL)1e9+5;
		for(int i=0; i<m; i++)
		{
			sort(maxArr, maxArr+3);
			if(minVol>maxArr[2])
				minVol=maxArr[2];
			maxArr[2]/=2;
		}
		sort(maxArr, maxArr+3);
		if(minVol>maxArr[2])
			minVol=maxArr[2];
		printf("%lld\n", minVol);
	}
	return 0;
}
