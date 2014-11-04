#include<stdio.h>

int main()
{
	int tc, i;
	scanf("%d", &tc);
	for(i=0; i<tc; i++)
	{
		int size, n1, n2;
		scanf("%d", &size);
		size = (1<<size) - 1;
		scanf("%d%d", &n1, &n2);
		while(n1 != n2) 
		{
			if(n1 > n2) n1=n1/2;
			else if(n1 < n2) n2=n2/2;
		}
		printf("%d\n", n1);
	}
	return 0;
}
