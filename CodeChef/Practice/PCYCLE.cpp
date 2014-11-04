#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define Sint(n) scanf("%lld", &n)
#define SUint(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

vector< vector<int> > cycles;

void find_cycle(int, int*, int*);

int main()
{
	int n;
	SI(n);
	int arr[1005];
	int visited[1005]={0};
	int count=0;
	for(int i=1; i<n+1; i++)
		SI(arr[i]);
	for(int i=1; i<n+1; i++)
	{
		if(!visited[i])
		{
			find_cycle(i, arr, visited);
			count++;
		}
	}
	cout<<count<<endl;
	for(int i=0; i<count; i++)
	{
		int l=cycles[i].size();
		int j;
		for(j=0; j<l-1; j++)
			printf("%d ",cycles[i][j]);
		printf("%d\n", cycles[i][j]);
	}
	return 0;
}

void find_cycle(int index, int *arr, int *visited)
{
	VI cyc;
	cyc.pb(index);
	cyc.pb(arr[index]);
	visited[index]=1;
	int num=arr[index];
	while(num!=index)
	{
		visited[num]=1;
		num=arr[num];
		cyc.pb(num);
	}
	cycles.pb(cyc);
}
