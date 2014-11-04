#include<stdio.h>
#include<math.h>

double dist(double x1, double y1, double x2, double y2);
int main()
{
	double x1, y1, x2, y2, x3, y3, x4, y4;
	long long int n, i=0;
	scanf("%lld", &n);
	while(i<n)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		double l13, l14, l22, l21;
		l13= (y2-y1)*(x3-x1)-(x2-x1)*(y3-y1);
		l14= (y2-y1)*(x4-x1)-(x2-x1)*(y4-y1);
		l21= (y3-y4)*(x1-x3)-(x3-x4)*(y1-y3);
		l22= (y3-y4)*(x2-x3)-(x3-x4)*(y2-y3);
		double dist1, dist2, dist3, dist4,dista,distb;
		dist1=dist(x1,y1,x3,y3);
		dist2=dist(x2,y2,x3,y3);
		dist3=dist(x1,y1,x4,y4);
		dist4=dist(x2,y2,x4,y4);
		dista=dist(x3,y3,x4,y4);
		distb=dist(x1,y1,x2,y2);
		if(fabs(dista-dist1-dist3)<0.00001||fabs(dista-dist2-dist4)<0.00001||fabs(distb-dist1-dist2)<0.00001||fabs(distb-dist3-dist4)<0.00001)
			printf("YES\n");
		else if(l13==0||l14==0&&l21==0||l22==0)
			printf("NO\n");
		else if(l13*l14<=0&&l22*l21<=0)
			printf("YES\n");
		else	printf("NO\n");
		i++;
	}
	return 0;
}

double dist(double x1, double y1, double x2, double y2)
{
	double distance;
	distance=sqrt(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
	return distance;
}
