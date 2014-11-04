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
	while(tc--)
	{
		string a, b;
		cin>>a>>b;
		int carry = 0;
		int maxlength = max(a.length(), b.length());
		vector<char> c(maxlength+5);
		for(int i=0; i<maxlength; i++)
		{
			if(!a[i]) {
				a[i] = '0';
				a[i+1] = 0;
			}
			else if(!b[i]) {
				b[i] = '0';
				b[i+1] = 0;
			}
			int sum = a[i] + b[i] + carry - 2 * '0';
			c[i] = sum%10 + '0';
			carry = sum/10;
			c[i+1] = 0;
		}
		if(carry)
			c[maxlength] = carry + '0';
		int flag = 0;
		for(int j=0; j<c.size(); j++)
		{
			if(c[j]!='0')
				flag = 1;
			if(flag)
				cout<<c[j];
		}
		cout<<endl;
	}
	return 0;
}
