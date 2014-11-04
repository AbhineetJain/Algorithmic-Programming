#include<stdio.h>
#include<math.h>

int main()
{
	long long int N, T, i=0, j=1,sum;
	long double sqroot;
	scanf("%lld", &T);
	for(i=0; i<T; i++)
	{
		sum=1;
		scanf("%lld", &N);
		sqroot=sqrt(N);
		if(N==1)
			printf("0\nNo\n");
		else
		{
			for(j=2; j<=sqroot; j++)
			{
		  	    if(N%j==0)
			    {	
				sum=sum+j+(N/j);
				if(j==sqroot)
					sum=sum-j;
			    }
			}
			printf("%lld\n", sum);
			if(sum==N)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}
