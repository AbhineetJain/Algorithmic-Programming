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
	vector<pair<int, int> > errors;
	int n;
	SI(n);
	int val;
	for(int i=0; i<n; i++)
	{
		SI(val);
		errors.insert(mp(val, 0));
	}
	for(int i=0; i<n-1; i++)
	{
		SI(val);
	}
	for(int i=0; i<n-2; i++)
	{
		SI(val);
		errors[val] = 1;
	}
	map<int, int>::iterator it = errors.begin();
	for(; it!=errors.end(); ++it)
	{
		if(it->s == 0)
			cout<<it->f<<endl;
	}
	return 0;
}
