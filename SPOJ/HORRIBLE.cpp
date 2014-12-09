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
	VLL tree1, tree2;
	int size;
    
    public:
	
	void clear(int n)
	{
		size = n;
		tree1.resize(size+1);
		tree2.resize(size+1);
		for(int i=0; i<=size; i++)
		{
			tree1[i] = tree2[i] = 0;
		}
	}

	void rangeUpdate(int start, int end, LL val)
	{
		add(tree1, start, val);
		add(tree1, end+1, -val);
		add(tree2, start, val*(start-1));
		add(tree2, end+1, -val*(end));
	}
	
	LL pointQuery(int index)
	{
		return index * sum(tree1, index) - sum(tree2, index);
	}

	LL rangeQuery(int start, int end)
	{
		return pointQuery(end) - pointQuery(start - 1);
	}

	LL sum(VLL &tree, int index)
	{
		LL add = 0;
		while(index)
		{
			add += tree[index];
			index -= index & -index;
		}
		return add;
	}

	void add(VLL &tree, int index, LL val)
	{
		while(index <= size)
		{
			tree[index] += val;
			index += index & -index;
		}
	}
};

int main()
{
	int n, c, tc;
	Fenwick f_tree;
	int query, p, q;
	LL val;
	SI(tc);
	while(tc--)
	{
		SI(n); SI(c);
		f_tree.clear(n);
		while(c--)
		{
			SI(query);
			if(query)
			{
				scanf("%d%d", &p, &q);
				printf("%lld\n", f_tree.rangeQuery(p, q));
			}
			else
			{
				scanf("%d%d%lld", &p, &q, &val);
				f_tree.rangeUpdate(p, q, val);
			}
		}
	}
	return 0;
}
