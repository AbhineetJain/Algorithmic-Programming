#include<stdio.h>

int main()
{
	long long int T, term, t1, t2, t3, tn, i=0,j=2;
	scanf("%lld", &T);
	for(i=0; i<T; i++)
	{
		scanf("%lld %lld %lld %lld", &t1, &t2, &t3, &term);
		if(term==1)
			printf("%lld\n", t1);
		else if(term==2)
			printf("%lld\n", t2);
		else if(term==3)
			printf("%lld\n", t3);
		else
		{
			for(j=3;j<term;j++)
			{
				tn=t1+t2+t3;
				t1=t2;
				t2=t3;
				t3=tn;
			}
			printf("%lld\n", tn);
		}
	}
	return 0;
}
			
