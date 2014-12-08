#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int arr[15];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	int dp[15];
	dp[0]=1;
	int max;
	for(int i=1; i<n; i++)
	{
		max=1;
		for(int j=0; j<i; j++)
		{
			if(arr[j]<arr[i])
				if(1+dp[j]>max)
					max=1+dp[j];
		}
		dp[i]=max;
	}
	printf("%d\n", dp[n-1]);
	return 0;
}
