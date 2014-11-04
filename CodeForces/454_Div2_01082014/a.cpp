#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n;
	int noD = -1;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		if(i <= n/2)
			noD+=2;
		else
			noD-=2;
		int noS = (n - noD)/2;
		for(int j=0; j<noS; j++)
			printf("*");
		for(int j=0; j<noD; j++)
			printf("D");
		for(int j=0; j<noS; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}

