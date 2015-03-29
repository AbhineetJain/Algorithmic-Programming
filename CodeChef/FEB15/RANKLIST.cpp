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

int main()
{
	int tc;
	SI(tc);
	LL n, s;
	while(tc--)
	{
		SLL(n); SLL(s);
		if(2*s == n*(n + 1))
			cout << 0 << endl;
		else if(n == s)
			cout << n-1 << endl;
		else
		{
			LL count = n-1;
			s -= n;
			int i = 1;
			while(s >= i)
			{
				s -= i;
				i++;
//				cout << s << endl;
				count--;
			}
			cout << count << endl;
		}
	}
	return 0;
}
