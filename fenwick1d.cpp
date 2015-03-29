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
	VLL tree;
	int size;

    public:
	void pointUpdate(int index, int value)
	{
		while(index <= size)
		{
			tree[index] += value;
			index += index & -index;
		}
	}

	LL getRange(int start, int end)
	{
		return sum(end) - sum(start - 1);
	}

	LL sum(int index)
	{
		LL add = 0;
		while(index)
		{
			add += tree[index];
			index -= index & -index;
		}
		return add;
	}

	void printTree()
	{
		for(int i = 1; i<=size; i++)
			printf("%lld ", tree[i]);
		printf("\n");
	}
	
	Fenwick(int n)
	{
		size = n;
		tree.resize(size+1);
	}
};

int main()
{
	int n, q;
	SI(n); SI(q);
	Fenwick f_tree(n);
	LL val;
	for(int i = 1; i<=n; i++)
	{
		SLL(val);
		f_tree.pointUpdate(i, val);
	}
	int query, val1, val2;
	for(int i =0 ; i<q; i++)
	{
		getchar();
		query = getchar();
		SI(val1); SI(val2);
		if(query == 'S')
		{
			printf("%lld\n", f_tree.getRange(val1+1, val2+1));
		}
		else if(query == 'G')
		{
			f_tree.pointUpdate(val1+1, val2);
		}
		else
		{
			f_tree.pointUpdate(val1+1, -val2);
		}
	}
	return 0;
}
