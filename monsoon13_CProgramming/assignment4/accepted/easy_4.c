#include<stdio.h>

int main()
{
	int tc, i, j;
	unsigned int n;
	int p;
	unsigned int check=(1<<31);
	scanf("%d", &tc);
	for(i=0; i<tc; i++)
	{
		scanf("%u %d", &n, &p);
		for(j=0; j<p; j++)
		{
			if((n&check)==check)
			{
				n=n<<1;
				n=n+1;
			}
			else
				n=n<<1;
		}
		printf("%u\n", n);
	}	
	return 0;
}
