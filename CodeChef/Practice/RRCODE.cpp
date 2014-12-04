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
	int tc, n;
	LL k, ans;
	SI(tc);
	while(tc--)
	{
		SI(n);
		SLL(k); SLL(ans);
		VLL numbers;
		LL input;
		for(int i=0; i<n; i++)
		{
			SLL(input);
			numbers.pb(input);
		}
		char op[5];
		scanf("%s", op);
		LL temp = numbers[0];
		if(k != 0)
		{
			if(op[0] == 'X')
			{
				for(int i=1; i<n; i++)
					temp = temp ^ numbers[i];
				if(k%2==0)
					temp = 0;
				ans = ans ^ temp;
			}
			else if(op[0] == 'O')
			{
				for(int i=1; i<n; i++)
					temp = temp | numbers[i];
				ans = ans | temp;
			}
			else
			{
				for(int i=1; i<n; i++)
					temp = temp & numbers[i];
				ans = ans & temp;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
