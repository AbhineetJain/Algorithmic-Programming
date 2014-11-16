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

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	int n, k;
	SI(n); SI(k);
	int drawAng[11];
	bool check[365] = {0};
	for(int i=0; i<n; i++)
		SI(drawAng[i]);
	for(int j=0; j<n; j++)
	{
		int val = drawAng[j];
		for(int i=1; i<=360; i++)
			check[(val*i)%360] = 1;
	}
	int gcdval = 360;
	for(int i=0; i<360; i++)
		if(check[i] == 1)
			gcdval = gcd(gcdval, gcd(i, 360));
	int query;
	for(int i = 0; i<k; i++)
	{
		SI(query);
		query = query % 360;
		if(query % gcdval == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
