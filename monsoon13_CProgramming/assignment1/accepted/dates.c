#include<stdio.h>
#include<math.h>

double juliannum(int  dd, int  mm, long long int yy);

int main()
{
	int dd1, mm1, dd2, mm2;
	long long int yy1, yy2, n, i=0;
	scanf("%lld", &n);
	while(i<n)
	{
	  scanf("%d %d %lld %d %d %lld", &dd1, &mm1, &yy1, &dd2, &mm2, &yy2);
	  double j1=juliannum(dd1, mm1, yy1);
	  double j2=juliannum(dd2, mm2, yy2);
	  printf("%.0lf\n",fabs(j1-j2)+1);
	  i++;
	}
	return 0;
}

double juliannum( int dd, int mm, long long int yy)
{
	double juliannum;
	long long int a, b, c, e, f;
	if(mm==1||mm==2)
	{
	  yy=yy-1;
	  mm=mm+12;
	}
	a=yy/100;
	b=a/4;
	c=2-a+b;
	e=365.25*(yy+4716);
	f=30.6001*(mm+1);
	juliannum=c+dd+e+f-1524.5;
	return juliannum;
} 
	  
