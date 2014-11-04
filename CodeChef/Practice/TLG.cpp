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
	LL n,a=0,b=0,score1,score2;
	SLL(n);
	LL max=0, diff, p;
	for(int i=0; i<n; i++)
	{
		SLL(score1);
		SLL(score2);
		a+=score1;
		b+=score2;
		diff=a-b;
		if(abs(diff)>max) {
			max=abs(diff);
			if(diff<0)
				p=2;
			else
				p=1;
		}
	}
	printf("%lld %lld\n", p, max);
	return 0;
}
