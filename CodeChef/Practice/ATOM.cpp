#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long int tc, n, k, m;
	scanf("%lld", &tc);
	while(tc--)
	{
		scanf("%lld%lld%lld", &n, &k, &m);
		long long int ans=0;	
		if(n>m)
			ans=1;
		while(n<=m)
		{
			m=m/k;
			ans++;
		}
		printf("%lld\n", ans-1);
	}
	return 0;
}
