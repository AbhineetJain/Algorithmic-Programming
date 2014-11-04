#include<stdio.h>
#include<math.h>

int main()
{
	double x1, y1, x2, y2, x3, y3, x4, y4;
	long long int n, i=0;
	double A, A1, A2, A3;
	scanf("%lld", &n);
	while(i<n)
	{
		scanf("%lf %lf", &x1,&y1);
		scanf("%lf %lf", &x2,&y2);
		scanf("%lf %lf", &x3,&y3);
		scanf("%lf %lf", &x4,&y4);
		A=fabs(0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
		A1=fabs(0.5*(x1*(y2-y4)+x2*(y4-y1)+x4*(y1-y2)));
		A2=fabs(0.5*(x1*(y4-y3)+x4*(y3-y1)+x3*(y1-y4)));
		A3=fabs(0.5*(x4*(y2-y3)+x2*(y3-y4)+x3*(y4-y2)));
		double diff;
		diff=A-(A1+A2+A3);
		if(fabs(diff)<0.00001)
		{ printf("YES\n"); }
		else
		{ printf("NO\n"); }
		i++;
	}
	return 0;
}

