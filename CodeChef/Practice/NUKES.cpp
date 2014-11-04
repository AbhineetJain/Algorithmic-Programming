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
	LL a, n, k;
	scanf("%lld%lld%lld", &a, &n, &k);
	a=a%((LL)pow(n+1,k));
	if(n==0)
		while(k--)
			printf("0 ");
	else {
		for(int i=0; i<k; i++)
		{
			printf("%lld ", a%(n+1));
			a/=(n+1);
		}
	}
	printf("\n");
	return 0;
}
