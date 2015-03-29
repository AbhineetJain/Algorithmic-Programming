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
	int n, m;
	SI(n); SI(m);
	string l1, l2;
	map<string, string> lang;
	for(int i=0; i<m; i++)
	{
		cin >> l1;
		cin >> l2;
		if(l1.length() <= l2.length())
			lang[l2] = l1;
		else
			lang[l1] = l2;
	}
//	for(map<string,string>::iterator iter = lang.begin(); iter!=lang.end(); iter++)
//		cout << iter->first << '\t' << iter->second << endl;
	for(int i=0; i<n; i++)
	{
		cin >> l1;
//		cout << l1;
		if(lang.find(l1) != lang.end())
			cout << lang[l1];
		else
			cout << l1;
		if(i<n-1)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}
