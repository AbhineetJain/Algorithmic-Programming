#include<stdio.h>

int main()
{
	int x, y, n, i=0, a;
	scanf("%d", &n);
	while(i<n)
	{
	  scanf("%d %d", &x, &y);
	  a=x;
          while(a<=x*y)
          { 
            if(a%x==0 && a%y==0)
            { break; }
            a=a+x;
          }
	  printf("%d\n", a);
	  i++;
	}
	return 0;
}
