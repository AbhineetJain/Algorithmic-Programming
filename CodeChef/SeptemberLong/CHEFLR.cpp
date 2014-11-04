#include<bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int main()
{
	int tc;
	char path[100005];
	scanf("%d", &tc);
	for(int i=0; i<tc; i++)
	{
		scanf("%s", path);
		int ans = 1;
		for(int j=0; path[j]!='\0'; j++)
		{
			if (path[j]=='l')
			{
				if(j%2 == 0)
					ans=(ans*2)%MOD;
				else
					ans=((ans*2)-1)%MOD;
			}
			else
			{
				if(j%2 == 0)
					ans=((ans+1)*2)%MOD;
				else
					ans=((ans*2)+1)%MOD;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
