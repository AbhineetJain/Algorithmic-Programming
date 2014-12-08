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

LL wordLen;
LL *table;

void failure(char *word)
{
	LL pos = 1, cnd = 0;
	table[0] = 0;
	while(pos < wordLen)
	{
		if(word[pos] == word[cnd])
		{
			cnd++;
			table[pos] = cnd;
			pos++;
		}
		else if(cnd > 0)
			cnd = table[cnd-1];
		else
		{
			table[pos] = 0;
			pos++;
		}
	}
}

int main()
{
	char *word;
	int ch, ans;
	int iter, haystackCount;
	while(scanf("%lld", &wordLen) != EOF)
	{
		iter = 0;
		haystackCount = 0;
		word = (char *)malloc(sizeof(char)*(wordLen+1));
		table = (LL *)malloc(sizeof(LL)*(wordLen));
		scanf("%s", word);
		failure(word);
//		for(int i=0; i<wordLen; i++)
//			printf("%lld ", table[i]);
//		printf("\n");
		getchar();
		ans = -1;
		ch = getchar();
		while(ch != '\n')
		{
//			cout << iter << " " << word[iter] << " " << char(ch) << " " << haystackCount << endl;
			if(word[iter] == ch)
			{
				iter++;
//				cout << "I was here\n";
				ch = getchar();
				haystackCount++;
			}
			if(iter == wordLen)
			{
				printf("%d\n", haystackCount-iter);
				iter = table[iter - 1];
				ans = 1;
//				cout << "I was here too\n";
			}
			else if(word[iter] != ch)
			{
				if(iter != 0)
					iter = table[iter - 1];
				else 
				{
					ch = getchar();
					haystackCount++;
				}
//				cout << "I was here though\n";
			}
		}
		if(ans == -1)
			printf("\n");
	}
	return 0;
}
