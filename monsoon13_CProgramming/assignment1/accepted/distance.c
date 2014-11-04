#include<stdio.h>
#include<math.h>

int main()
{
	int n;
	float x1, x2, y1, y2;
	int i=0;
	float dist2;
	scanf("%d", &n);
	while(i<n)
	{
	  scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
	  dist2=((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
	  printf("%.1f\n", 1.0*sqrt(dist2));
	  i++;
	}
	return 0;
}
