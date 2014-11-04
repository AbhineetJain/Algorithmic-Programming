#include<stdio.h>

int main()
{
	float n;
	float ans;
	while(~scanf("%f", &n))
	{
		ans=(float)(n/2+n/3+n/4);
		printf("%d\n", (int)ans);
	}
	return 0;
}
