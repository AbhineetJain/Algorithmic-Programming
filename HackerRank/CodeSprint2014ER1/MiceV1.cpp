#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long int tc, n, m, mouse[131075], hole[131075];
	scanf("%lld", &tc);
	while(tc--)
	{
		scanf("%lld%lld", &n, &m);
		for(int i=0; i<n; i++)
			scanf("%lld", &mouse[i]);
		for(int i=0; i<m; i++)
			scanf("%lld", &hole[i]);
		sort(mouse, mouse+n);
		sort(hole, hole+m);
		long long int ans=0;
		for(int i=0; i<n; i++)
			ans = max(abs(hole[i]-mouse[i]), ans);
		printf("%lld\n", ans);
	}
	return 0;
}
