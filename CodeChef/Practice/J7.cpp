#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SD(n) scanf("%lf", &n)
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
	SI(tc);
	while(tc--)
	{
		double wire, sheet;
		SD(wire); SD(sheet);
		wire/=4; sheet/=2;
		double length1 = (wire+sqrt(wire*wire-3*sheet))/3; 
		double length2 = (wire-sqrt(wire*wire-3*sheet))/3;
		double volume = max(length1*sheet-(length1*length1)*(wire-length1),length2*sheet-(length2*length2)*(wire-length2));
		printf("%.2lf\n", volume);
	}
	return 0;
}
