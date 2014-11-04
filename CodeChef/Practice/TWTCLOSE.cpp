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
	int tweets, clicks;
	SI(tweets); SI(clicks);
	char operation[10];
	bool open[1005];
	int count=0;
	for(int i=0; i<tweets; i++)
		open[i]=0;
	for(int i=0; i<clicks; i++)
	{
		int tweetNo;
		scanf("%s", operation);
		if(strcmp(operation, "CLICK")==0)
		{
			SI(tweetNo);
			if(open[tweetNo-1]==0)
			{
				open[tweetNo-1]=1;
				count++;
			}
			else
			{
				open[tweetNo-1]=0;
				count--;
			}
		}
		else if(strcmp(operation, "CLOSEALL")==0)
		{
			for(int j=0; j<tweets; j++)
				open[j]=0;
			count=0;
		}
		printf("%d\n", count);
	}
	return 0;
}
