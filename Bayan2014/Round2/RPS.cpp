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
	int tc;
	SI(tc);
	getchar();
	for(int i=0; i<tc; i++)
	{
		int n;
		SI(n);
		string game;
		cin>>game;
		getchar();
		VI wins(n);
		for(int j=0; j<n; j++)
		{
			if(game[j]=='S')
			{	for(int k=0; k<n; k++)
				{
					if(game[k]=='P')
						wins[j]++;
			}	}
			else if(game[j]=='R')
			{	for(int k=0; k<n; k++)
				{
					if(game[k]=='S')
						wins[j]++;
			}	}
			else if(game[j]=='P')
			{	for(int k=0; k<n; k++)
				{
					if(game[k]=='R')
						wins[j]++;
			}	}
		}
		int max=-1, count=0;
		for(int j=0; j<n; j++)
		{
			if(wins[j]>max)
			{
				max=wins[j];
				count = 1;
			}
			else if(wins[j] == max)
				count++;
		}
		printf("Case #%d:\n%d\n", i+1, count);
	}
	return 0;
}
