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
	LL a, b;
	cin >> a >> b;
	if(a == 1)
		cout << b << endl;
	else if(b == 1)
		cout << a << endl;
	else if(a == b) cout << 1 << endl;
	else
	{
		LL count = 0;
		LL newmaxi, newmini;
		LL maxi = (a > b)?a:b;
		LL mini = (a > b)?b:a;
		while(mini > 0)
		{
			count += maxi/mini;
			newmaxi = mini;
			newmini = maxi%mini;
			maxi = newmaxi;
			mini = newmini;
		}
		cout << count << endl;
	}
	return 0;
}
