#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, c, D;
	int n;
	scanf("%d", &n);
	int i=0;
	while(i<n)
	{
		scanf("%lf %lf %lf", &a, &b, &c);
		D=(b*b)-(4*a*c);
		if(D>=0)
		{
			printf("%.2lf %.2lf\n", (-b-sqrt(D))/(2*a), (-b+sqrt(D))/(2*a));
		}
		else
		{
			printf("%.2lf - i%.2lf,%.2lf + i%.2lf\n", -b/(2*a), sqrt(-D)/(2*a), -b/(2*a), sqrt(-D)/(2*a));
		}
		i++;
	}
	return 0;
} 
