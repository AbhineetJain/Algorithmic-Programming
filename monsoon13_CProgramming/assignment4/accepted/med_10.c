#include<stdio.h>

void calcfridge(long long int ice, long long int maxice);

long long int fridge;
int main()
{
	long long int tc, i;
	long long int ice, maxice;
	scanf("%lld", &tc);
	for(i=0; i<tc; i++)
	{
		scanf("%lld %lld", &ice, &maxice);
		fridge=0;
		calcfridge(ice, maxice);
		printf("%lld\n", fridge);
	}
	return 0;
}

void calcfridge(long long int ice, long long int maxice)
{
	long long int temp1, temp2;
	if(ice<=maxice)
		fridge++;
	else{
	temp1=ice/2;
	temp2=ice-temp1;
	if(temp1>maxice)
		calcfridge(temp1, maxice);
	else
		fridge++;
	if(temp2>maxice)
		calcfridge(temp2, maxice);
	else 
		fridge++;
	}
}
