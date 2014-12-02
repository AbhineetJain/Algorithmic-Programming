#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long int tc, l, r;
	scanf("%lld", &tc);
	while(tc--)
	{
		scanf("%lld%lld", &l, &r);
		long long int ans=0, prev=-1;
		for(long long int i=l; i<=r; i++)
		{	
			long long int pow10 = (long long int)log10(i);
			if(pow10>prev)
			{	prev=pow10;
				long long int k=i;
				

			ans+=((i*((long long int)log10(i)+1))%1000000007);
		}
		printf("%lld\n", ans%1000000007);

	}
	return 0;
}
