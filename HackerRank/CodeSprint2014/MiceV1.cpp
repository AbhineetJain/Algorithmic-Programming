#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long int tc, n, mouse[131075], hole[131075];
	scanf("%lld", &tc);
	while(tc--)
	{
		scanf("%lld", &n);
		for(int i=0; i<n; i++)
			scanf("%lld", &mouse[i]);
		for(int i=0; i<n; i++)
			scanf("%lld", &hole[i]);
		sort(mouse, mouse+n);
		sort(hole, hole+n);
		long long int ans=0;
		for(int i=0; i<n; i++)
			ans = max(abs(hole[i]-mouse[i]), ans);
		printf("%lld\n", ans);
	}
	return 0;
}
