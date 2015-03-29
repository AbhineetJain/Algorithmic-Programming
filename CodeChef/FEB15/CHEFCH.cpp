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
	string chain;
	char comp = '+';
	int count1, count2;
	while(tc--)
	{
		count1 = count2 = 0;
		cin >> chain;
		comp = '+';
		for(int i=0; i<(int)chain.size(); i++)
		{
			if(chain[i] != comp)
				count1++;
			if(comp == '+')
				comp = '-';
			else
				comp = '+';
		}
		comp = '-';
		for(int i=0; i<(int)chain.size(); i++)
		{
			if(chain[i] != comp)
				count2++;
			if(comp == '+')
				comp = '-';
			else
				comp = '+';
		}
		cout << min(count1, count2) << endl;
	}
	return 0;
}
