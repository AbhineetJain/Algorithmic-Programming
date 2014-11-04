#include<stdio.h>

unsigned int reverse(unsigned int a);
int main()
{
	unsigned int bit1=0, bit2=0;
	unsigned int rev1=0, rev2=0;
	long long int sum=0;
	while(~scanf("%u %u", &bit1, &bit2))
	{
		rev1=reverse(bit1);
		rev2=reverse(bit2);
		sum=(long long int)rev1+(long long int)rev2;
		printf("%llu\n", sum);
	}
	return 0;
}

unsigned int reverse(unsigned int a)
{
	unsigned int ans=0,temp=0, count=31;
	while(count!=0)
	{
		temp=(a&1);
		temp<<=count;
		ans|=temp;
		count--;
		a>>=1;
	}
	return ans;
}
	

