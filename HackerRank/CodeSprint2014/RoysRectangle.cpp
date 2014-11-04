#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long int tc;
	scanf("%lld", &tc);
	long long int x, y, x1, y1, x2, y2;
	while(tc--)
	{
		scanf("%lld%lld%lld%lld%lld%lld", &x, &y, &x1, &y1, &x2, &y2);
		int min1 = min(abs(x1-x), abs(x2-x));
		int min2 = min(abs(y1-y), abs(y2-y));
		printf("%lld\n", min(min1, min2));
	}
	return 0;
}
