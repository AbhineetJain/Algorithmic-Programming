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
	int tc, n;
	SI(tc);
	while(tc--)
	{
		SI(n);
		map<string, int> votes;
		char vote;
		string userid;
		for(int i=0; i<n; i++)
		{
			cin>>userid>>vote;
			if(vote=='+')
				votes[userid]=1;
			else
				votes[userid]=-1;
		}
		int total=0;
		for(map<string, int>::iterator it=votes.begin(); it!=votes.end(); ++it)
			total+=it->second;
		printf("%d\n", total);
	}
	return 0;
}
