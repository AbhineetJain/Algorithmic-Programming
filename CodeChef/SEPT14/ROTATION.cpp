#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	int array[100005];
	for(int i=0; i<n; i++)
		scanf("%d", &array[i]);
	int currIndex = 0;
	for(int i=0; i<q; i++)
	{
		char query;
		int d;
		getchar();
		scanf("%c%d", &query, &d);
		switch(query)
		{
			case 'R':
				printf("%d\n", array[(currIndex+d-1)%n]);
				break;
			case 'C':
				currIndex+=(d%n);
				currIndex%=n;
				break;
			case 'A':
				currIndex+=((n-d)%n);
				currIndex%=n;
				break;
		}
	}
	return 0;
}
