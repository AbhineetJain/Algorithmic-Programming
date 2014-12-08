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
	vector<pair<LL,LL> > vill(100005), dino(100005);
	SLL(tc);
	while(tc--)
	{
		SLL(n);
		LL inVal;
		int i, j, k;
		for(i=j=k=0; i<n; i++)
		{
			SLL(inVal);
			if(inVal<0)
			{
				dino[j].s=i;
				dino[j++].f=inVal;
			}
			else
			{
				vill[k].s=i;
				vill[k++].f=inVal;
			}
		}
		int villSize=k;
		int dinoSize=j;
		/* for(int x=0; x<villSize; x++)
		   cout<<vill[x].f<<"("<<vill[x].s<<") ";
		   cout<<endl;
		   for(int x=0; x<dinoSize; x++)
		   cout<<dino[x].f<<"("<<dino[x].s<<") ";
		   cout<<endl;
		 */	LL dist=0;
		for(i=0, j=0; i<villSize && j<dinoSize; )
		{
			if(vill[i].f>-1*dino[j].f)
			{
				dist+=(-1*dino[j].f*abs(dino[j].s-vill[i].s));
				vill[i].f+=dino[j].f;
				dino[j].f=0;
				j++;
			}
			else
			{
				dist+=(vill[i].f*abs(vill[i].s-dino[j].s));
//				if(vill[i].f==abs(dino[j].f))
//					j++;
				dino[j].f+=vill[i].f;
				vill[i].f=0;
				i++;
			}
			// cout<<i<<" "<<j<<endl;
		}
		printf("%lld\n", dist);
	}
	return 0;
}
