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
	char string[100005];
	while(tc--)
	{
		scanf("%s", string);
		int balance = 0, maxbalance = 0;
		for(int i=0; string[i]!='\0'; i++)
		{
			if(string[i] == '(')
				balance++;
			else
				balance--;
			if(balance > maxbalance) maxbalance = balance;
		}
		for(int i=0; i<maxbalance; i++)
			printf("(");
		for(int i=0; i<maxbalance; i++)
			printf(")");
		printf("\n");
	}
	return 0;
}
