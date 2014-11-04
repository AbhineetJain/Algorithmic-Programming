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
	LL q;
	string alph;
	cin >> q >> alph;
	while(q--)
	{
		string input;
		cin >> input;
		for(int i=0; i<input.length(); i++)
		{
			if(input[i] == '_')
				printf(" ");
			else if(input[i]>=65 && input[i]<=90)
				printf("%c", alph[input[i]+32-'a']-32);
			else if(input[i]>=97 && input[i]<=122)
				printf("%c", alph[input[i]-'a']);
			else
				printf("%c", input[i]);
		}
		cout << endl;
	}
	return 0;
}
