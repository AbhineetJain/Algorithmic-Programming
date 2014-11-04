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
	int tc, r;
	vector< pair<int, int> > pos(4);
	SI(tc);
	while(tc--)
	{
		SI(r);
		for(int i=0; i<3; i++)
		{	
			SI(pos[i].f);
			SI(pos[i].s);
		}
		int count=0;
		for(int i=0; i<3; i++)
		{
			LL dist = (pos[i].f-pos[(i+1)%3].f)*(pos[i].f-pos[(i+1)%3].f)+(pos[i].s-pos[(i+1)%3].s)*(pos[i].s-pos[(i+1)%3].s);
			if(dist<=r*r)
				count++;
			if(count==2)
				break;
		}
		if(count==2)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
