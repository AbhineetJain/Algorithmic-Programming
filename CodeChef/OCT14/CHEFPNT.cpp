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
	int n, m, k;
	SI(n); SI(m); SI(k);
	bool board1[105][105];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			board1[i][j] = 0;
		}
	}
	int x, y;
	for(int i=0; i<k; i++)
	{
		SI(x); SI(y);
		board1[x-1][y-1] = 1;
	}
	vector<pair<int,int> > horPts, verPts;
	for(int i=0; i<n; i++)
	{
		int add=1, j;
		for(j=0; j<m; j++)
		{
			if(board1[i][j]==0 && add)
			{
				horPts.pb(mp(i+1, j+1));
				add = 0;
			}
			else if(board1[i][j]==1)
				add = 1;
		}
	}
	for(int i=0; i<m; i++)
	{
		int add=1, j;
		for(j=0; j<n; j++)
		{
			if(board1[j][i]==0 && add)
			{
				verPts.pb(mp(j+1, i+1));
				add = 0;
			}
			else if(board1[j][i]==1)
				add = 1;
		}
		
	}
	int minSize = min(horPts.size(), verPts.size());
	printf("%d\n", minSize);
	if(minSize == horPts.size())
	{
		for(int i=0; i<horPts.size(); i++)
		{
			printf("%d %d %d\n", horPts[i].f, horPts[i].s, 0);
		}
	}
	else
	{
		for(int i=0; i<verPts.size(); i++)
		{
			printf("%d %d %d\n", verPts[i].f, verPts[i].s, 1);
		}
	}
	return 0;
}
