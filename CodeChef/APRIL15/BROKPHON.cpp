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
	int n;
	int count = 0;
	cin >> tc;
	int prev, curr;
	int flag = 0;
	while(tc--)
	{
		cin >> n;
		cin >> prev;
		flag = 0;
		count = 0;
		for(int i=1; i<n; i++)
		{
			cin >> curr;
			if(curr != prev)
			{
				if(flag)
					count++;
				else
					count += 2;
				flag = 1;
			}
			else
				flag = 0;
			prev = curr;
		}
		cout << count << endl;
	}
	return 0;
}
