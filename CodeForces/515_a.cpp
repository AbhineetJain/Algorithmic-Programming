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
	LL a, b, s;
	SLL(a); SLL(b); SLL(s);
	a = abs(a); b = abs(b);
	if(s < a+b)
		cout << "No\n";
	else if(s == a+b)
		cout << "Yes\n";
	else if((s - (a+b)) % 2 == 0)
		cout << "Yes\n";
	else 
		cout << "No\n";
	return 0;
}
