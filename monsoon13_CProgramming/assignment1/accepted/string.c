#include<stdio.h>

int main()
{
	int n, i=0;
	char x;
	scanf("%d", &n);
	while(i<n)
	{
	  scanf("%c", &x);
	  if(x==10||x==32)
	  { scanf("%c", &x); } 
	  if(x>='A' && x<='Z')
	  { printf("UPPER CASE CHARACTER\n"); }
	  else
	  {
		if(x>='a' && x<='z')
		{ printf("LOWER CASE CHARACTER\n"); }
		else
		{
		  if(x>='0' && x<='9')
		  { printf("NUMERAL\n"); }
		  else
		  { printf("NON-ALPHANUMERAL\n"); }
		}
	  }
	  i++;
	}
	return 0;
}
