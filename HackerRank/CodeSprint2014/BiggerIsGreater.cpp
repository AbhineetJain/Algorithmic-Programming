#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long int tc;
	cin>>tc;
	char w[105];
	while(tc--)
	{
		scanf("%s", w);
		if(next_permutation(w, w+strlen(w)))
			printf("%s\n",w);
		else
			printf("no answer\n");
	}
	return 0;
}
