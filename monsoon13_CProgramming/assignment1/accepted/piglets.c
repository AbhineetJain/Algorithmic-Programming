#include<stdio.h>

int main()
{
	long long int N, P, n, i=0;
	long long int min, max;
	scanf("%lld", &n);
	while(i<n)
	{
	  scanf("%lld %lld", &N, &P);
	  if(P%2==0)
	  { max=N-(P/2);}
	  else
	  { max=N-(P/2)-1;}
	  if(P>N)
	  { min=0;}
	  else
	  { min=N-P;} 
	  printf("%lld %lld\n", min, max);
	  i++;
	}
	return 0;
}
