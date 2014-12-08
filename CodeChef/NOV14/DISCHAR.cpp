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
	int check[28] = {0};
	int count = 0;
	while(tc--)
	{
		count = 0;
		for(int i=0; i<26; i++)
			check[i] = 0;
		scanf("%s", inp);
		for(int i=0; inp[i]!='\0'; i++)
		{
			if(not check[inp[i]-'a'])
			{
				check[inp[i]-'a']++;
				count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
