#include<stdio.h>

int main()
{
	long int l, b, x, y, r;
	long int N;
	scanf("%d", &N);
	long int i=0;
	while(i<N)
	{
	 scanf("%d %d", &l,&b);
	 x=l;
	 y=b;
	 if(x*y==0)
	 { printf("0\n"); }
	 else
	 {
	  while(y!=0)
          {
                r=x%y;
                x=y;
                y=r;
	  }
	  printf("%d\n", x);
	 }
	 i++;
	}
	return 0;
}
