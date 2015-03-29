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
	char inp;
	int weights[130] = {0};
	weights['q'] = weights['Q'] = 9;
	weights['r'] = weights['R'] = 5;
	weights['b'] = weights['B'] = 3;
	weights['n'] = weights['N'] = 3;
	weights['p'] = weights['P'] = 1;
	int white = 0, black = 0;
	for(int i = 0; i< 8 ; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			cin >> inp;
			if(inp == '.')
				continue;
			else if( inp >= 65 && inp <= 90 )
				white+=weights[inp];
			else
				black+=weights[inp];
		}
		getchar();
	}
	if (black > white)
		cout << "Black\n";
	else if (black < white)
		cout << "White\n";
	else
		cout << "Draw\n";
	return 0;
}
