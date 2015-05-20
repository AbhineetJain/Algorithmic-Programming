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
	int n;
	cin >> n;
	char org[1005];
	char com[1005];
	int count = 0;
	cin >> org >> com;
	for(int i = 0; i < n; i++)
	{
		count += min(abs(org[i] - com[i]), 10 - abs(org[i] - com[i]));
	}
	cout << count << endl;
	return 0;
}
