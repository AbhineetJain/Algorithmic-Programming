#include<stdio.h>
#include<math.h>

int main()
{
	long long int num, i, flag=0;
	double sqroot;
	scanf("%lld", &num);
	sqroot=sqrt(num);
	for(i=3; i<=sqroot; i+=2)
	{
		if(num%i==0 && (num-1)%(i-1)==0 && (num/i)%i!=0)
			flag++;
	}
	if(flag>=3)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
