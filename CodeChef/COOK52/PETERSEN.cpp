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

int adMat[11][11] = { {1, 4, 5}, {0, 2, 6}, {1, 3, 7}, {2, 4, 8}, {0, 3, 9}
{0, 7, 8}, {1, 8, 9}, {2, 5, 9}, {3, 5, 6}, {4, 6, 7} };

int retIndex(char v)
{
	return v - 'A';
}

int main()
{
	int tc;
	SI(tc);
	char string[100005];
	while(tc--)
	{
		scanf("%s", string);
		for(int i=0; string[i]!='\0'; i++)
		{
			
		}
	}
	return 0;
}
