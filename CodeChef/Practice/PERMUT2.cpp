#include<bits/stdc++.h>

int main()
{
	long long int i, n, arr[100005], perm[100005];
	scanf("%lld", &n);
	while(n!=0)
	{
		for(i=0; i<n; i++)
		{
			scanf("%lld", &arr[i]);
			perm[arr[i]-1]=i+1;
		}
		
		for(i=0; i<n; i++)
		{
			if(arr[i]!=perm[i])
			{
				printf("not ambiguous\n");
				break;
			}
		}
		if(i==n)
			printf("ambiguous\n");
		scanf("%lld", &n);
	}
	return 0;
}
