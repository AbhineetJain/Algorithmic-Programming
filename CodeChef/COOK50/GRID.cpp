#include<bits/stdc++.h>

int main()
{
	long long int n, tc;
	scanf("%lld", &tc);
	char map[1005][1005];
	long long int row[1005], col[1005];
	while(tc--)
	{
		scanf("%lld", &n);
		for(int i=0; i<n; i++)
			row[i]=-1;
		for(int i=0; i<n; i++)
			col[i]=-1;
		for(int i=0; i<n; i++)
			scanf("%s", map[i]);
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(map[i][j]=='#')
				{
					row[i]=j;
					col[j]=i;
				}
			}

		}
		long long int count=0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(j>row[i] && i>col[j])
					count++;
			}
		}
		printf("%lld\n", count);
	}
	return 0;
}
