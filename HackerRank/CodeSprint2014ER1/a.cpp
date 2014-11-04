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
	string s;
	cin>>s;
	VI alpha(26, 0);
	VI count(s.length(), 0);
	for(int i=0; i<s.length(); i++)
	{
		if(alpha[s[i]-'a']==0){
			count[i]++;
			alpha[s[i]-'a']++;
		}
		if(i>0 && s[i]==s[i-1] && count[i-1]==1)
		{
			alpha[s[i]-'a']++;
			count[i]++;
		}
	}
	int min=1e5+5, index;
	for(int i=0; i<26; i++)
	{
		if(alpha[i]<min)
		{
			min=alpha[i];
			index=i;
		}
	}
	for(int i=0; i<min+1; i++)
		printf("%c", 'a'+index);
	printf("\n");
	return 0;
}
