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
	LL x, k;
	while(tc--)
	{
		SLL(x); SLL(k);
		int powOfTwo = (int)log2(k);
		LL expOfTwo = ((LL)(1)<<powOfTwo);
		expOfTwo -= 1;
//		printf("%lld ", expOfTwo);
		LL denominator = (double)2*(expOfTwo + 1);
//		cout<<denominator<<" ";
		double numerator = (double)(k - expOfTwo)*2 - 1;
//		cout<<numerator<<" ";
		printf("%lf\n", (double)x*(numerator/denominator));
	}
	return 0;
}
