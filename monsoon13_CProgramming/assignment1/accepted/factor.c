#include<stdio.h>

int main()
{
	int a, b, n, i=0;
	scanf("%d", &n);
	while(i<n)
	{
	  scanf("%d%d", &a, &b);
	  
	  if(a==0||b==0||a%b==0 || b%a==0 )
	  {
	   printf("YES\n");
	  }
	  else
	  {
	   printf("NO\n");
	  }
	  i++;
	}
	return 0;
}
