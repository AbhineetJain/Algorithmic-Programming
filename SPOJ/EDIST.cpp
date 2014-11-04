#include<bits/stdc++.h>

using namespace std;

int min(int a, int b, int c)
{
	if(a<b)
	{
		if(a<c) return a;
		else return c;
	}
	if(b<c)	return b;
	else return c;
}

int main()
{
	char str1[2005], str2[2005];
	int tc;
	int **dp=NULL;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%s%s", str1, str2);
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		dp=(int **)malloc(sizeof(int *)*(len1+1));
		for(int i=0; i<len1+1; i++)
			dp[i]=(int *)malloc(sizeof(int)*(len2+1));		
		for(int i=0; i<len1+1; i++)
		{
			for(int j=0; j<len2+1; j++)
			{
				if(j==0) dp[i][j]=i;
				else if(i==0) dp[i][j]=j;
				else if (str1[i-1]==str2[j-1])
					dp[i][j] = min(1+dp[i-1][j], 1+dp[i][j-1], dp[i-1][j-1]);
				else
					dp[i][j] = min(1+dp[i-1][j], 1+dp[i][j-1], 1+dp[i-1][j-1]);
			}
		}
		printf("%d\n", dp[len1][len2]);
	}
	return 0;
}
