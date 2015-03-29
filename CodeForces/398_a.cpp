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

void splprint(char c, int num)
{
	for(int i=0; i<num; i++)
		printf("%c", c);
}

int main()
{
	LL a, b;
	SLL(a); SLL(b);
	if (b == 0)
	{
		cout << a * a << endl;
		for (int i = 0; i < a; i++)
			cout << "o";
		cout << endl;
		return 0;
	}
	if (b == 1)
	{
		cout << a * a - 1 << endl;
		for (int i = 0; i < a; i++)
			cout << "o";
		cout << "x";
		cout << endl;
		return 0;
	}
	if (a == 0)
	{
		cout << -1 * b * b << endl;
		for (int i = 0; i < b; i++)
			cout << "x";
		cout << endl;
		return 0;
	}
	LL ans = INT_MIN, o1, o2, x1, x2, P, I;
	for (LL i = 2; i <= min(a + 1, b); i++)
	{
		LL p = b/i;
		LL q = b%i;
		LL val = (-p*p*(i - q)) - (q*(p+1)*(p+1));
//		cout << p << " " << q << " " << i << " " << val << endl;
		val += ((i - 2) + ((a - (i - 2))*(a - (i - 2))));
//		cout << val << endl;
		if (val > ans)
		{
			ans = val;
			o1 = 1;
			o2 = a - (i - 2);
			x1 = p;
			x2 = p + 1;
			P = q;
			I = i;
		}
	}
	cout << ans << endl;
/*	for (LL i = 0; i < o2; i++)
		cout << "o";
	for (LL i = 0; i < min(x1, o1); i++)
	{
		for (LL i = 0; i < P; i++)
			cout << "x";
		cout << "o";
	}
*/	int c1 = I-2, c2 = I - P - 1;
	splprint('x', x1);
	for(int i=1; i<I; i++)
	{
		if(c1)
		{
			c1--;
			splprint('o', o1);
		}
		else
			splprint('o', o2);
		if(c2)
		{
			c2--;
			splprint('x', x1);
		}
		else
			splprint('x', x2);
	}
	cout<<endl;
	return 0;
}
