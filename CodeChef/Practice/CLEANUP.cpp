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
	LL tc, n, m;
	SLL(tc);
	while(tc--)
	{
		SLL(n);
		VI jobs(n, 0);
		SLL(m);
		LL in;
		for(int i=0; i<m; i++){
			SLL(in);
			jobs[in-1]=1;
		}
		int prev=3;
		for(int i=0; i<n; i++){
			if(jobs[i]!=1 && prev!=2){
				jobs[i]=2;
				prev=2;
			}
			else if(jobs[i]!=1 && prev!=3)
			{
				jobs[i]=3;
				prev=3;
			}
		}
		for(int i=0; i<n; i++)
			if(jobs[i]==2)
				printf("%d ", i+1);
		printf("\n");
		for(int i=0; i<n; i++)
			if(jobs[i]==3)
				printf("%d ", i+1);
		printf("\n");
	}
	return 0;
}
