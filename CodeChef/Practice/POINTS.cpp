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

bool comp(pair<LL, LL> i, pair<LL, LL> j)
{ 
	if(i.f == j.f) 
		return i.s > j.s; 
	return i.f < j.f; 
}

int main()
{
	int tc;
	SI(tc);
	int n, x, y, x1, x2, y1, y2;
	double dist;
	while(tc--)
	{
		getchar();
		dist = 0;
		vector<pair<int, int> > points(100005);
		SI(n);
		for(int i=0; i<n; i++)
		{
			SI(x); SI(y);
			points[i] = mp(x, y);
		}
		sort(points.begin(), points.begin() + n, comp);
		for(int i=0; i<n-1; i++)
		{
			x1 = points[i].f; x2 = points[i+1].f;
			y1 = points[i].s; y2 = points[i+1].s;
			dist += sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
		}
		printf("%.2lf\n", dist);	
	}
	return 0;
}
