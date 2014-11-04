#include<bits/stdc++.h>

using namespace std;

int main()
{
	int ip, flag=0;
	while(scanf("%d", &ip)!=EOF)
	{	
		if(ip==42) flag=1;
		if(flag==0) printf("%d\n", ip);
	}
	return 0;
}
