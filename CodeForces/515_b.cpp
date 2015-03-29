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
	int n, m;
	SI(n); SI(m);
	VI boys(n+5, 0);
	VI girls(m+5, 0);
	int b, g, ind;
	SI(b);
	for(int i=0; i<b; i++)
	{
		SI(ind);
		boys[ind] = 1;
	}
	SI(g);
	for(int i=0; i<g; i++)
	{
		SI(ind);
		girls[ind] = 1;
	}
	for(int i=0; i<2*m*n; i++)
	{
//		cout << i << " " << boys[i%n] <<" " << i%n << " " << girls[i%m] << " " << i%m << endl;
		girls[i%m] = boys[i%n] = boys[i%n] | girls[i%m];
	}
//	for(int i=0; i<n; i++)
//		cout << boys[i] << " ";
//	cout << endl;
//	for(int i=0; i<m; i++)
//		cout << girls[i] << " ";
//	cout << endl;
	for(int i=0; i<n; i++)
	{
		if(!boys[i])
		{
			cout << "No\n";
			return 0;
		}
	}
	for(int i=0; i<m; i++)
	{
		if(!girls[i])
		{
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
