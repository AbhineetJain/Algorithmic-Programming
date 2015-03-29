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

char ans[10];
void convbin(int integer)
{
	ans[0] = '\0';
	for(int i=7; i>=0; i--)
	{
		if(integer >= 1 << i)
		{
			ans[7-i] = '1';
			integer -= (1 << i);
		}
		else
			ans[7-i] = '0';
	}
	ans[8] = '\0';
}

int main()
{
	int tc;
	int n;
	SI(tc);
	while(tc--)
	{
		vector<string> ips;
		vector<string> binips;
		SI(n);
		ips.resize(n);
		binips.resize(n);
		int integer;
		char str[35];
		if(n == 1)
		{
			cin >> ips[0];
			cout << ips[0] << "/32\n";
		}
		else{
		for(int i=0; i<n; i++)
		{
			integer = 0;
			str[0] = '\0';
			cin >> ips[i];	
			for(int j=0; ips[i][j]!='\0'; j++)
			{
				if(ips[i][j] == '.')
				{
					convbin(integer);
					strcat(str, ans);
					integer = 0;
				}
				else
				{
					integer = integer*10 + (ips[i][j]-'0');
				}
			}
			convbin(integer);
			strcat(str, ans);
			binips[i] = str;
		}
		sortv(binips);
		int slash;
		for(int i=0; i<32; i++)
		{	
			if(binips[0][i] != binips[n-1][i])
			{
				slash = i;
				break;
			}
		}
		for(int i=31; i>=slash; i--)
		{
			binips[0][i] = '0';
		}
		int cn = 0;
		for(int i=0; i<32; i++)
		{
			if(i%8 == 0 and i!= 0) {
				cout << cn << '.';
				cn = 0;
			}
			if(binips[0][i] == '1')
				cn += (1 << (7 - (i%8)));

		}
		cout << cn << '/' << slash << endl;
		}
	}
	return 0;
}
