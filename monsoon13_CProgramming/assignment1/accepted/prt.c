#include<stdio.h>
#include<math.h>

int main()
{
	int t, n, i=0;
	double X, R, P;
	scanf("%d", &n);
	while(i<n)
	{
	  scanf("%lf %d %lf", &X, &t, &R);
	  P=X/pow((1+R/1200), (12*t));
	  printf("%.2f\n", P);
	  i++;
	}
	return 0;
}

