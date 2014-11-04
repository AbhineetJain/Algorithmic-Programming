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
	string s;
	LL t;
	SLL(t);
	while (t--)
	{
		cin >> s;
		for (int i = s.length() - 1; i >= 0; --i)
			cout << s[i];
		cout << endl;
	}
	return 0;
}
