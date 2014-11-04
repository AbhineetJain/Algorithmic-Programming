#include<stdio.h>

int main()
{
	double r1, r2, r3, r4, r5, v;
	long int n, i=0;
	double R1, R2, I;
	double i1, i2, i3, i4, i5;
	scanf("%ld", &n);
	while(i<n)
	{
	  scanf("%lf %lf %lf %lf %lf %lf", &r1, &r2, &r3, &r4, &r5, &v);
	  R1=r1*r2/(r1+r2);
	  R2=(r3*r4*r5)/(r3*r4+r4*r5+r5*r3);
	  I= v/(R1+R2);
	  i1=r2*I/(r1+r2);
	  i2=r1*I/(r1+r2);
	  i3=R2*v/((R1+R2)*r3);
	  i4=R2*v/((R1+R2)*r4);
	  i5=R2*v/((R1+R2)*r5);
	  printf("%.1lf %.1lf %.1lf %.1lf %.1lf\n", i1, i2, i3, i4, i5);
	  i++;
	}
	return 0;
}
