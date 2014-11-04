#include<bits/stdc++.h>

using namespace std;

int main()
{
	int hash[27]={0};
	long long int tc;
	scanf("%lld", &tc);
	char b[28], w[105];
	while(tc--)
	{
		scanf("%s%s", b, w);
		for(int i=0; b[i]!='\0'; i++)
			hash[b[i]-'a']++;
		int count=0;
		for(int i=0; w[i]!='\0'; i++)
		{
			if(hash[w[i]-'a']==1)
			{
				count++;
				hash[w[i]-'a']++;
			}
		}
		for(int i=0; i<26; i++){
			hash[i]=0;
		}
		printf("%d\n", count);
	}
	return 0;
}
