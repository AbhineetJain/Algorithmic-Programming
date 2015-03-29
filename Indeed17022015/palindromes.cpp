#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int tc;
	SI(tc);
	char str[1005], ans[1005], ansfinal[1005];
	int maxlen;
	int len;
	for(int m=0; m<tc; m++)
	{
		ansfinal[0] = '\0';
		maxlen = 0;
		len = 0;
		scanf("%s", str);
		int j;
		for(int i=0; str[i]!='\0'; i++)
		{
			for(j=i; str[j]!='\0'; j++)
			{
				if(str[i] == str[j])	
				{
					len = 0;
					for(int k=i, l=j; k<=l; k++, l--)
					{
						if(str[k] != str[l])
						{
							len = 0;
							break;
						}
						else
						{
							if(k==l)
								len++;
							else
								len+=2;
						}
//						cout << str[k] << " " << str[l] << endl;
					}
				}
			
//			cout << len << endl;
			if(len >= maxlen)
			{
				ans[0] = '\0';
				int l, k;
				for(k=i, l=0; k<=j; k++, l++)
					ans[l] = str[k];
				ans[l] = '\0';
//				cout << ans << endl;
			}
			if(len == maxlen)
			{
				if(strcmp(ansfinal, ans) > 0)	
					strcpy(ansfinal, ans);
			}
			else if(len > maxlen)
			{
				strcpy(ansfinal, ans);
				maxlen = len;
			}
//			cout << ansfinal << endl;
			}
		}
		printf("%s\n", ansfinal);
	}
	return 0;
}
