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
	while(tc--)
	{
		string a, b;
		LL children;
		VI hash(27);
		cin >> a >> b;
		cout << a << b;
		for(int i=0; i<a.length(); i++)
			hash[a[i]-'a']++;
		for(int i=0; i<b.length(); i++)
			hash[b[i]-'a']++;
		cin >> children;
		while(children--)
		{

		}
	}
	return 0;
}
