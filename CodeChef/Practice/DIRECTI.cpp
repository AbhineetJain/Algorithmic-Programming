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
	LL tc, n;
	SLL(tc);
	while(tc--)
	{
		SLL(n);
		string on;
		vector< pair<string,string> > dir(n);
		for(int i=0; i<n; i++)
		{
			cin>>dir[i].f;
			cin>>on;
			int c, j=0;
			char ch[50];
			while((c=getchar()) != '\n')
			{
				ch[j]=c;
				j++;
			}
			ch[j]='\0';
			dir[i].s=ch;
		}
		string direct;
		for(int i=n-1; i>=0; i--)
		{
			if(i==n-1)
				direct="Begin";
			else
			{
				if(dir[i+1].f[0]=='L')
					direct="Right";
				else
					direct="Left";
			}
			cout<<direct<<" on"<<dir[i].s<<endl;
		}
		cout<<endl;
	}
	return 0;
}
