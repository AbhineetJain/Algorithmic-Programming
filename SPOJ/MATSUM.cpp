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

class Fenwick
{
	vector<VLL> tree;
	int size;

    public:
	void pointAdd(int i, int j, int value)
	{
		int r = i, c = j;
		while(r <= size)
		{
			c = j;
			while(c <= size)
			{
				tree[r][c] += value;
				c += c & -c;
			}
			r += r & -r;
		}
	}

	LL getRange(int i1, int j1, int i2, int j2)
	{
		return sum(i2, j2) - sum(i1-1, j2) - sum(i2, j1-1) + sum(i1-1, j1-1);
	}

	LL sum(int i, int j)
	{
		int r = i, c = j;
		LL add = 0;
		while(r)
		{
			c = j;
			while(c)
			{
				add += tree[r][c];
				c -= c & -c;
			}
			r -= r & -r;
		}
		return add;
	}

	void pointSet(int i, int j, int val)
	{
		pointAdd(i, j, val - getRange(i, j, i, j));
	}

	void printTree()
	{
		for(int i = 1; i<=size; i++)
		{
			for(int j = 1; j<=size; j++)
				printf("%lld ", tree[i][j]);
			printf("\n");
		}
	}
	
	Fenwick(int n)
	{
		size = n;
		tree.resize(size+1);
		for(int i=0; i<=size; i++)
			tree[i].resize(size+1);
	}
};

int main()
{
	LL tc;
	SLL(tc);
	while(tc--)
	{
	
		int n;
		SI(n);
		int r, c, r1, c1;
		LL val;
		Fenwick f_tree(n);
		char query[4];
		do
		{
			scanf("%s", query);
			if(query[1] == 'E')
			{
				scanf("%d%d%lld", &r, &c, &val);
				f_tree.pointSet(r+1, c+1, val);
			}
			else if(query[1] == 'U')
			{
				scanf("%d%d%d%d", &r, &c, &r1, &c1);
				printf("%lld\n", f_tree.getRange(r+1, c+1, r1+1, c1+1));
			}
		}while(query[0] != 'E');
	}
	return 0;
}
