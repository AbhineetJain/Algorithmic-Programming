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
	char inp[100005];
	while(tc--)
	{
		scanf("%s", inp);
		int flag = 0, i, j;
		for(i=0, j=strlen(inp)-1; i<j; i++, j--)
		{
			if(inp[i] != inp[j])
			{
				break;
			}
		}
		for(int k = i+1, l = j; k<l; k++, l--)
		{
			if(inp[k] != inp[l])
			{
				flag = 1;
				break;
			}
		}
		if(flag)
		{
			flag  = 0;
			for(int k = i, l = j - 1; k<l; k++, l--)
			{
				if(inp[k] != inp[l])
				{
					flag = 2;
					break;
				}

			}
		}
		if(!flag)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
