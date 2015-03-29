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

#define MAXN 200000

int n, visited[MAXN];
vector<pair<int, int> > graph[MAXN];
VI topoOrder;

void dfs(int i)
{
	if(visited[i]) return;
	visited[i] = true;
	for(int j=0; j<graph[i].length(); j++)
	{
		dfs(graph[i][j].f);
	}
}

int main()
{
	return 0;
}
