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

double prob[2005][2005];

int main()
{
	memset(prob, 0, sizeof(prob));
	int n, t;
	double p, total = 0.0;
	SI(n);
	scanf("%lf", &p);
	SI(t);
	prob[0][0] = 1;
	for(int i=1; i<=t; i++)
	{
		prob[i][0] = prob[i-1][0]*(1-p);
	}
	for(int i=1; i<=t; i++)
	{
		for(int j=1; j<=i && j<=n; j++)
		{
			prob[i][j] = prob[i-1][j-1]*p + ((j == n)?0:(prob[i-1][j]*(1-p)));
		}
	}
	for(int i=1; i<=t; i++)
	{
		total += prob[t][i]*i;
	}
	for(int i=1; i<t; i++)
	{
		total += prob[i][n]*n;
	}
	printf("%.6f\n", total);
	return 0;
}
