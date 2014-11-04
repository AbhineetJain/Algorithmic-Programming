#include<stdio.h>
#include<math.h>

int main()
{
	double P;
	int n;
	double A=0;
	int N, i=0;
	scanf("%d", &N);
	while(i<N)
	{
	 scanf("%lf %d", &P, &n);
	 int y=0;
	 double Q=P;
	 while(y<n)
	 {
	   A=(P*1.12);
	   A=A-(Q/10);
	   P=A;
	   y++;
	 }	   
	 printf("%.6lf\n", P);
	 i++;
	}
	return 0;
}
