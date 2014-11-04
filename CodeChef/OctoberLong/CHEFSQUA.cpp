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
	pair<double, double> points[2005];
	for(int i=0; i<n; i++)
	{
		scanf("%lf%lf", &points[i].f, &points[i].s);
	}
	if(n<3)
		printf("%d\n", 4-n);
	else
	{
		double halfX, halfY, midX, midY, newX, newY;
		sort(points, points+n);
		int maxcount=0;
		for(int i=0; i<n-1; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				int count=0;
//				cout<<points[i].f<<", "<<points[i].s<<" & "<<points[j].f<<", "<<points[j].s<<endl;
				midX = (points[i].f+points[j].f)/2;
				midY = (points[i].s+points[j].s)/2;
				halfX = (points[i].f-points[j].f)/2;
				halfY = (points[i].s-points[j].s)/2;
//				cout<<midX<<" "<<midY<<endl;
				newX = midX+halfY;
				newY = midY-halfX;
				if(binary_search(points, points+n, mp(newX,newY)))
					count++;
//				cout<<newX<<", "<<newY<<endl;
				newX = midX-halfY;
				newY = midY+halfX;
				if(binary_search(points, points+n, mp(newX,newY)))
					count++;
//				cout<<newX<<", "<<newY<<endl;
				if(count>maxcount)
					maxcount=count;
				if(count==2)
					break;
//				cout<<"Count: "<<count<<endl;
			}
			if(maxcount==2)
				break;
		}
		printf("%d\n", 2-maxcount);
	}
	return 0;
}
