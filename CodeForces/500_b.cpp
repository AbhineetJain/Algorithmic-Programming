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
	int n;
	SI(n);
	VI perm(n+5);
	VI index(INT_MAX);
	VI sorted(n+5);
	for(int i=1; i<=n; i++)
	{
		SI(perm[i]);
		index[perm[i]] = i;
		sorted[i] = perm[i];
	}
	int swapcheck[305][305];
	getchar();
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			swapcheck[i][j] = getchar() - '0';
		getchar();
	}
/*	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			cout << swapcheck[i][j];
		cout << endl;
	}
*/	int flag;
	int a, b;
	sort(sorted.begin()+1, sorted.begin()+n+1);
	for(int i=1; i<=n; i++)
	{
		flag = 1;
		for(int j=i; j<index[sorted[i]]; j++)
		{
			flag = 0;
			if(swapcheck[index[sorted[i]]][j] == 1)
			{
				a = index[sorted[i]]; b = j;
				perm[a] = perm[b] + perm[a] - (perm[b] = perm[a]);
				index[perm[a]] = index[perm[b]] + index[perm[a]] - (index[perm[b]] = index[perm[a]]);
				flag = 1;
			}
/*			for(int k=1; k<=n; k++)
				cout << perm[k] << " ";
			cout << endl;
			for(int k=1; k<=n; k++)
				cout << index[k] << " ";
			cout << endl;
*/			if(flag == 1)
				break;
		}
		for(int j=index[sorted[i]]+1; j<=i; j++)
		{
			flag = 0;
			if(swapcheck[index[sorted[i]]][j] == 1)
			{
				a = index[sorted[i]]; b = j;
				perm[a] = perm[b] + perm[a] - (perm[b] = perm[a]);
				index[perm[a]] = index[perm[b]] + index[perm[a]] - (index[perm[b]] = index[perm[a]]);
				flag = 1;
			}
/*			for(int k=1; k<=n; k++)
				cout << perm[k] << " ";
			cout << endl;
			for(int k=1; k<=n; k++)
				cout << index[k] << " ";
			cout << endl;
*/			if(flag == 1)
				break;
		}
//		cout << i;
		if(flag == 0)
			break;
	}
	for(int i=1; i<=n; i++)
		printf("%d ", perm[i]);
	printf("\n");
	return 0;
}
