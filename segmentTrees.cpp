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

class segTree
{
	VI tree;
	int size;
	int interior_nodes;
    
    public:
    	
	void update(int index, int val)
	{
		index = interior_nodes + index;
		//val = val - tree[index]; /* for set function */
		while(index > 0)
		{
			tree[index] += val;
			index = (index-1)/2;
		}
		tree[index] += val;
	}

	int query(int start, int end, int checkS, int checkE, int index)
	{
		if(start <= checkS && end >= checkE)
		{
			return tree[index];
		}
		if(start > checkE || end < checkS)
		{	
			return 0;
		}
		int mid = checkS + (checkE - checkS)/2;
		return query(start, end, checkS, mid, 2*index+1) + query(start, end, mid+1, checkE, 2*index+2);
	}

	segTree(int n)
	{
		size = 2*n - 1;
		interior_nodes = size/2;
		tree.resize(size);
	}

	void printTree()
	{
		for(int i = 0; i < size; i++)
			printf("%d ", tree[i]);
		printf("\n");
	}
};

int main()
{
	int n, q, val;
	SI(n);
	int inp_no = n;
	n = 1 << int(ceil(log2(n)));
	segTree seg_tree(n);
	SI(q);
	for(int i = 0; i<inp_no; i++)
	{
		SI(val);
		seg_tree.update(i, val);
	}
	char q_type;
	int val1, val2;
	while(q--)
	{
		getchar();
		q_type = getchar();
		scanf("%d%d", &val1, &val2);
		if(q_type == 'S')
			printf("%d\n", seg_tree.query(val1, val2, 0, n-1, 0));
		else if(q_type == 'G')
			seg_tree.update(val1, val2);
		else if(q_type == 'T')
			seg_tree.update(val1, -val2);
	}
	return 0;
}
