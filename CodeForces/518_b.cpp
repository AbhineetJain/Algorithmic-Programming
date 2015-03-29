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
	string a, b;
	cin >> a >> b;
	int match1[128] = {0}, match2[128] = {0};
	int yaycount = 0, whoopscount = 0;
	for(int i=0; a[i]; i++)
	{
		match1[a[i]] += 1;
	}
	for(int i=0; b[i]; i++)
	{
		match2[b[i]] += 1;
	}
	for(int i=0; i<128; i++)
	{
		if(match1[i] <= match2[i])
		{
			yaycount += match1[i];
			match2[i] -= match1[i];
			match1[i] = 0;
		}
		else
		{
			yaycount += match2[i];
			match1[i] -= match2[i];
			match2[i] = 0;
		}
	}
	for(int i=0; i<128; i++)
	{
		if(match1[i] != 0)
		{
			if(i <= 90)
			{
				if(match2[i+32] <= match1[i])
				{
					whoopscount += match2[i+32];
					match1[i] -= match2[i+32];
					match2[i+32] = 0;
				}
				else
				{
					whoopscount += match1[i];
					match2[i+32] -= match1[i];
					match1[i] = 0;
				}
			}
			else
			{
				if(match2[i-32] <= match1[i])
				{
					whoopscount += match2[i-32];
					match1[i] -= match2[i-32];
					match2[i-32] = 0;
				}
				else
				{
					whoopscount += match1[i];
					match2[i-32] -= match1[i];
					match1[i] = 0;
				}
			}
		}
	}
	cout << yaycount << " " << whoopscount << endl;
	return 0;
}
