#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

VLL comb(1000005);

int main()
{
	LL tc, n;
	cin >> tc;
	comb[0] = 0;
	for(int i=1; i<=1000000; i++)
	{
		comb[i] = comb[i-1] + i;
	}
	for(int i=1; i<=1000000; i++)
	{
		comb[i] = comb[i-1] + comb[i];
	}
	while(tc--)
	{
		cin >> n;
		cout << n;
		if(n==1) cout << 1 << endl;
		else cout << comb[n] + comb[n-1] - comb[n-2] << endl;
	}
	return 0;
}
