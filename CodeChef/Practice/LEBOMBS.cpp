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
	int tc,n;
	char arr[1005];
	SI(tc);
	while(tc--)
	{
		SI(n);
		scanf("%s", arr);
		int count=0;
		if(n==1)
		{
			if(arr[0]=='0')
				count++;
		}
		else
		{
			for(int i=0;i<n; i++)
			{
				if(arr[i]=='0')
				{
					if(i==0 && arr[1]=='0')
						count++;
					else if(i==n-1 && arr[n-2]=='0')
						count++;
					else if(arr[i+1]=='0' && arr[i-1] == '0')
						count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
