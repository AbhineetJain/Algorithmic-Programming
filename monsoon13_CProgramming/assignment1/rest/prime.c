#include<stdio.h>
#include<math.h>

int main()
{
	int num;
	int n, i=0, x,flag,k;
	scanf("%d", &n);
	while(i<n)
	{
		scanf("%d", &num);
		x=sqrt(num);
		flag=0;
		k=3;
		if(num==2||num==3)
		{ flag=0; }
		else if (num==1)
		{ flag=1; }
		else if((num%6==1)||(num%6==5))
		{
		 while(k<=x)
		 {
		  if(num%k==0)
		  {
		    flag++;
		    break;
		  }
		  k+=2;
		 }
		} 
		else
		{  flag=1; }
		if(flag==1) printf("FALSE\n");
		else printf("TRUE\n");
		i++;
	}
	return 0;
}
