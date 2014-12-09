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
	
	void insert(int val, int count)
	{
		if(count)
		{
			bool bit = val & 1;
			if(child[bit] == NULL)
				child[bit] = new trie;
			child[bit]->insert(val>>1, count-1);
		}
	}

	bool find(int val, int count)
	{
		if(count)
		{
			bool bit = val & 1;
			if(child[bit] == NULL)
				return false;
			return child[bit]->find(val>>1, count-1);
		}
		return true;
	}
};

void printtrie(trie *t);

int main()
{
	trie *bit_trie;
	bit_trie = new trie;
	int n, i, val;
	SI(i);
	while(i--)
	{
		SI(val);
		val = reverseInt(val);
		bit_trie->insert(val, 32);
	}
	printtrie(bit_trie);
	printf("\n");
	SI(n);
	while(n--)
	{
		SI(val);
		printf("%d\n", bit_trie->find(reverseInt(val), 32));
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
