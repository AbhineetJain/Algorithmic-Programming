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
	LL tc, k;
	SLL(tc);
	while(tc--)
	{
		string out="a";
		SLL(k);
		for(int i=0; i<k; i++)
		{
			if(i>=25)
			{
				k-=25;
				i=0;
				out.push_back('a');
			}
			out.push_back(i+1+'a');
		}
		reverse(out.begin(), out.end());
		cout<<out<<endl;
	}
	return 0;
}
