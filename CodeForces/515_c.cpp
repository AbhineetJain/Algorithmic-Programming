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
	map<char, string> dig;
	dig['2'] = "2";
	dig['3'] = "3";
	dig['4'] = "223";
	dig['5'] = "5";
	dig['6'] = "35";
	dig['7'] = "7";
	dig['8'] = "2227";
	dig['9'] = "2337";
	int n;
	SI(n);
	getchar();
	char inp;
	string ans="";
	for(int i=0; i<n; i++)
	{
		scanf("%c", &inp);
		if(inp!='1' and inp!='0')
			ans+=dig[inp];
	}
	sort(ans.begin(), ans.end(), greater<int>());
	cout << ans << endl;
	return 0;
}
