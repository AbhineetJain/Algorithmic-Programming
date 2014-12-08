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
	LL n;
	SLL(n);
	LL s_array[100005];
	LL pre_array[100005];
	LL prev = 0;
	for(int i = 0; i < n; i++)
	{
		SLL(s_array[i]);
		pre_array[i] = s_array[i] + prev;
		prev = pre_array[i];
	}
	sort(s_array, s_array + n);
	for(int i = 1; i<n; i++)
		s_array[i] += s_array[i - 1];
	LL m;
	SLL(m);
	int type, l, r;
	while(m--)
	{
		SI(type); SI(l); SI(r);
		l--; r--;
		if(type == 1)
		{
			if(l == 0)
				printf("%lld\n", pre_array[r]);
			else
				printf("%lld\n", pre_array[r] - pre_array[l-1]);
		}
		else if(type == 2)
		{
			if(l == 0)
				printf("%lld\n", s_array[r]);
			else
				printf("%lld\n", s_array[r] - s_array[l-1]);
		}
	}
	return 0;
}
