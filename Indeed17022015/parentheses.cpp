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
	string str;
	int count = 0, flips;
	while(tc--)
	{
		count = 0;
		flips = 0;
		cin >> str;
		if((int)str.size() % 2 == 1 )
			cout << "IMPOSSIBLE\n";
		else
		{
			for(int i=0; i<str.size(); i++)
			{
				if(str[i] == '(')
				{
					count++;
				}
				else if(str[i] == ')')
				{
					if(count == 0)
					{
						count++;
						flips++;
					}
					else
						count--;
				}
			}
			cout << count/2+flips << endl;
		}
	}
	return 0;
}
