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

int reverseInt(int val);

class trie
{
    public:
	trie *child[2];
	
	trie()
	{
		child[0] = child[1] = NULL;
	}
	
	void insert(int val, int count = 32)
	{
		if(count)
		{
			bool bit = val & 1;
			if(child[bit] == NULL)
				child[bit] = new trie;
			child[bit]->insert(val>>1, count-1);
		}
	}

	int find(int val, int count = 32, int ans = 0)
	{
		if(count)
		{
			bool bit = val & 1;
			if(child[1-bit] == NULL)
			{
				ans <<= 1;
				ans |= bit;
				return child[bit]->find(val>>1, count-1, ans);
			}
			else
			{
				ans <<= 1;
				ans |= (1-bit);
				return child[1-bit]->find(val>>1, count-1, ans);
			}
		}
		return ans;
	}
};

void printtrie(trie *t);

int main()
{
	trie *bit_trie;
	int tc, n, array[100005];
	SI(tc);
	while(tc--)
	{
		SI(n);
		bit_trie = new trie;
		for(int i=0; i<n; i++)
			SI(array[i]);
		int ans = 0, pre = 0;
		bit_trie->insert(0);
		for(int i = 0; i<n; i++)
		{
			pre = pre ^ array[i];
			bit_trie->insert(reverseInt(pre));
			ans = max(ans, bit_trie->find(reverseInt(pre))^pre);
		}
		printf("%d\n", ans);
		delete bit_trie;
	}
	return 0;
}

void printtrie(trie *t)
{
	if(t->child[0] != NULL)
	{
		printf("0");
		printtrie(t->child[0]);
	}
	if(t->child[1] != NULL)
	{
		printf("1");
		printtrie(t->child[1]);
	}
	printf("\n");
	return;
}

int reverseInt(int val)
{
	int rev = 0, i=32;
	while(i--)
	{
		rev = rev << 1;
		rev |= val & 1;
		val = val >> 1;
	}
	return rev;
}
