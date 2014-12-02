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
	LL tc;
	SLL(tc);
	char str[1000005];
	while(tc--)
	{
		scanf("%s", str);
		int len=strlen(str)-1;
		int mid=len/2;
		for(int i=mid; i>=0; i--)
		{
			int minimum=min(str[i], str[len-i]);
			str[i]=str[len-i]=minimum+1;
			printf("%c\n", minimum);
		}
	}
	return 0;
}
