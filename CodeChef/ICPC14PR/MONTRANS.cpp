#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SF(n) scanf("%f", &n)
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
	float dollar, cents, c;
	SI(tc);
	while(tc--)
	{
		SF(dollar); SF(cents); SF(c);
		float money, maxmoney;
		money = maxmoney = dollar + (cents/100);
//		cout << maxmoney << endl;
		int turn = 0, i = 0;
		if(c == 0)
			cout << "0" << endl;
		else {
			while(money > c/100)
			{
				money -= c/100;
				dollar = (int)money;
				cents = (int)((money-dollar)*100);
//				cout << money << " " << cents << " " << dollar << endl;
				money = cents + dollar/100;
	//			cout << money << " ";
				i++;
				maxmoney = max(money, maxmoney);
				if(maxmoney == money) turn = i;
	//			cout << money << endl;
			}
			cout << turn << endl;
		}
	}
	return 0;
}
