#include<bits/stdc++.h>

using namespace std;

bool pairCompare(const pair<long long int, long long int> &firstElem, const pair<long long int, long long int> &secondElem)
{
	return firstElem.second > secondElem.second;
}

int main()
{
	long long int n, m=0;
	scanf("%lld", &n);
	vector< pair <long long int,long long int> > objs(n);
	for(int i=0; i<n; i++)
	{
		scanf("%lld%lld", &objs[i].first, &objs[i].second);
		m+=objs[i].first;
	}
	sort(objs.begin(), objs.end(), pairCompare);
	for(int i=1; i<=m; i++)
	{
		long long int cost=0;
		long long int wt=i;
		for(int j=0; j<n; j++)
		{
			if(wt<=0)
				break;
			else if(objs[j].first<=wt)
			{
				cost+=objs[j].second;
				wt-=objs[j].first;
			}
		}
		printf("%lld ", cost);
	}
	printf("\n");
	return 0;
}
