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
	char str[105];
	int holes[27]={1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
	SI(tc);
	while(tc--)
	{
		scanf("%s", str);
		int count=0;
		for(int i=0; str[i]!='\0'; i++)
		{
			count+=holes[str[i]-'A'];
		}
		printf("%d\n", count);
	}
	return 0;
}
