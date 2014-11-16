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

int visited[160005];

int main()
{
	int tc;
	SI(tc);
	int n, l;
	map<int, int> ladders;
	while(tc--)
	{
		SI(n);
		SI(l);
		for(int i=0; i<=n; i++)
			visited[i] = -1;
		int b, u;
		for(int i=0; i<l; i++)
		{
			SI(b); SI(u);
			ladders[b] = u;
		}
		queue<int> bfsq;
		bfsq.push(1);
		visited[1] = 0;
		while(!bfsq.empty() && visited[n] == -1)
		{
			int head = bfsq.front();
			bfsq.pop();
			cout << head << " " << visited[head] << endl;
			if(ladders.find(head) != ladders.end())
			{
				if(visited[ladders[head]] == -1)
				{
					bfsq.push(ladders[head]);
					visited[ladders[head]] = visited[head];
				}
				else
					visited[ladders[head]] = min(visited[ladders[head]], visited[head]);
			}
			for(int i = head + 2; i <= min(head + 12, n); i++)
			{
				if(visited[i] == -1)
				{
					bfsq.push(i);
					visited[i] = visited[head] + 1;
				}
//				else
//					visited[i] = min(visited[i], visited[head] + 1);
			}
		}
		printf("%d\n", visited[n]);
	}
	return 0;
}
