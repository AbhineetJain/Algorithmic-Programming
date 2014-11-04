#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<class T> void print_array_v(T &a)
{
	int size = a.size();
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int s, q;
	char a[20200];
	int m, l;
	scanf("%s", a);
	s = strlen(a);
	scanf("%d", &q);
	for(int i=0; i<q; i++)
	{
		scanf("%d%d", &m, &l);
		LL sum = 0;
		vector< vector<int> >dp(s, vector<int>(m, 0));
		dp[0][(a[0]-'0')%m] = 1;
		sum = dp[0][l];
		for(int i=1; i<s; i++)
		{
			dp[i][(a[i]-'0')%m] = 1;
			for(int j=0; j<m; j++)
			{
				int ind = (10*j + a[i]-'0')%m;
				dp[i][ind] += dp[i-1][j];
			}
			sum += dp[i][l];
		}
		printf("%lld\n", sum);
	}
	return 0;
}

