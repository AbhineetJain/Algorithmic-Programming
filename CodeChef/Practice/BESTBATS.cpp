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

int ncr[12][12] = { 	{1, 1},
			{1, 2, 1},
			{1, 3, 3, 1},
			{1, 4, 6, 4, 1},
			{1, 5, 10, 10, 5, 1},
			{1, 6, 15, 20, 15, 6, 1},
			{1, 7, 21, 35, 35, 21, 7, 1},
			{1, 8, 28, 56, 70, 56, 28, 8, 1},
			{1, 9, 36, 84, 126, 126, 84, 36, 9, 1},
			{1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1},
			{1, 11, 55, 165, 330, 462, 462, 330, 165, 55, 11, 1}	};

int main()
{
	int tc;
	SI(tc);
	int scores[12];
	int count[101] = {0};
	while(tc--)
	{
		for(int i=0; i<100; i++)
			count[i] = 0;
		for(int i=0; i<11; i++)
		{
			SI(scores[i]);
			count[scores[i]]++;
		}
		int players;
		SI(players);
		sort(scores, scores+11, greater<int>());
		int countLast = 0;
		for(int i=0; i<players; i++)
			if(scores[i] == scores[players - 1])
				countLast++;
		cout<<ncr[count[scores[players-1]]-1][countLast];
		cout<<endl;	
	}
	return 0;
}
