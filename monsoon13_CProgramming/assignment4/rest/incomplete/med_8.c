#include<stdio.h>

int main()
{
	int tc, i;
	int n;
	int arr[1000];
	int j, size, k;
	int max=0, xor;
	scanf("%d", &tc);
	for(i=0; i<tc; i++)
	{
		scanf("%d", &n);
		for(j=0; j<n; j++)
			scanf("%d", &arr[j]);
		size=1<<(n);
		for(j=0; j<size; j++)
		{
			xor=0;
			for(k=0; k<n; k++)
			{
				if(j&(1<<k))
					xor=xor^arr[k];
			}
			if(xor>max)
				max=xor;
		}
		printf("%d\n", max);
	}
	return 0;
}

