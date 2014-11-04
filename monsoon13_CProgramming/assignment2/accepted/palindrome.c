#include<stdio.h>
#include<math.h>

int main()
{
	long long int num, num2, temp, digits,sum;
	long long int org, ten;
	double ratio;
	double part1, part2;
	while(~scanf("%lld", &num))
	{
		org=num;
		num2=digits=sum=0;
		while(num!=0)
		{
			temp=num%10;
			num=num/10;
			num2=num2*10+temp;
			sum=sum+temp;
			digits++;
		}
		if(org==num2)
		{	
		  printf("YES\n");
		  if((digits%2)==1)
			printf("%lld\n", sum);
		  else
		  {	
			ten=pow(10,(digits/2));
			part1=org/ten;
			part2=org%ten;
			if(part2==0)
				printf("0\n");
			else
			{
			 ratio=part1/part2;
			 printf("%.2lf\n", ratio);
			}
		  } 
		}
		else
		{
			printf("NO\n");
		}

	}
	return 0;
}
