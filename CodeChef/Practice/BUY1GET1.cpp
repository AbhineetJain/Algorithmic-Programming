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
	LL tc;
	SLL(tc);
	while(tc--)
	{
		string s;
		VI count(123,0);
		int total=0;
		cin>>s;
		for(int i=0; s[i]!='\0'; i++)
			count[s[i]]++;
		for(int i=0; i<123; i++)
			total=total+((count[i]%2)?(count[i]+1)/2:(count[i]/2));
		cout<<total<<endl;
	}
	return 0;
}
