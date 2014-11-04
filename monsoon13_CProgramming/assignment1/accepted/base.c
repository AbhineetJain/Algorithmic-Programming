#include<stdio.h>

int main()
{
	long long int num, base, n, i=0;
	scanf("%lld", &n);
	long long int r;
	while(i<n)
	{
	  scanf("%lld %lld", &num, &base);
	  long long int count=0;
	  while(num!=1)
	  {
		r=num%2;
	    	num=num/2;
	  	if(r==1)
	 	{ count++; }
	  }
	 long long int j=0;
	 long long int final=1, mult=base;
	 while(j<count)
	 {
	   	final=final+mult;
		mult=mult*base;
		j++;
	 }
	 printf("%lld\n", final);
	 i++;
	}
	return 0;
}
