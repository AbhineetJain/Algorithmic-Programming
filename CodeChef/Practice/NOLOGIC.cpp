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
	getchar();
	while(tc--)
	{
		int inp;
		bool check[27];
		for(int i=0; i<26; i++)
			check[i] = 0;
		while((inp = getchar()) != '\n')
		{
			if(inp>=65 && inp<=90)
				check[inp-'A'] = 1;
			else if(inp>=97 && inp<=122)
				check[inp-'a'] = 1;
		}
		int i;
		for(i=0; i<26; i++)
			if(check[i] == 0)
			{
				printf("%c\n", i+'a');
				break;
			}
		if(i == 26)
			printf("~\n");
	}
	return 0;
}
