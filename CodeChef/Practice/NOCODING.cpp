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
	string inp;
	SI(tc);
	while(tc--)
	{
		cin>>inp;
		int len=inp.length();
		int total=0;
		for(int i=0; i<len-1; i++)
		{
			if(inp[i+1]<inp[i])
				total+=(26+inp[i+1]-inp[i]);
			else
				total+=(inp[i+1]-inp[i]);
		}
		if(total<=10*len-1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
