#include<stdio.h>

int main()
{
	int n, i=0;
	long long int  N;
	scanf("%d", &n);
	while(i<n)
	{
	  scanf("%lld", &N);
	  int j=0;
	  long long int  r=0, p=1, sum=1;
	  while(j<N)
	  {
		sum=r+p;
		r=p;
		p=sum;
		j++;
	  }
	  printf("%lld\n", sum);
	  i++;
	} 
	return 0;
}
		
