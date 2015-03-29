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
	char str1[105], str2[105];
	char str3[105];
	scanf("%s", str1);
	scanf("%s", str2);
	int len = strlen(str1), j;
	for(int i=0; i<len; i++)
	{
		if(str1[i] == str2[i])
			str3[i] = str1[i];
		else
		{
			if(str2[i] - str1[i] > 1)
			{
				str3[i] = str1[i]+1;
				for(j=i+1; j<len; j++)
					str3[j] = 'a';
				str3[j] = '\0';
				break;
			}
			else
			{
				str3[i] = str1[i];
				for(j=i+1; j<len; j++)
					str3[j] = 'z';
				str3[j] = '\0';
				if(strcmp(str3, str1) != 0)
				{
					break;
				}
				else
				{
					str3[i] = str2[i];
					for(j=i+1; j<len; j++)
						str3[j] = 'a';
					str3[j] = '\0';
					if(strcmp(str3, str2)!=0)
						break;
					else {
						cout << "No such string\n";
						return 0;
					}
				}
			}
		}
	}
	cout << str3 << endl;
	return 0;
}
