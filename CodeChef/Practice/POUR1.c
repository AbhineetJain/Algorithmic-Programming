#include<stdio.h>
#include<math.h>

int gcd(int a, int b);
int ret_count(int a, int b, int c);

int main()
{
	int a, b, c, hcf, max, min, a1, a2, a3, tc;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d%d%d", &a, &b, &c);
		hcf=gcd(a,b);
		max=(a>b)?a:b;
		min=(a<b)?a:b;
		if(c==0)
			printf("0\n");
		else if(a<c&&b<c)
			printf("-1\n");
		else if(c%hcf!=0)
			printf("-1\n");
		else if(c==a||c==b)
			printf("1\n");
		else if(c==abs(a-b))
			printf("2\n");
		else
		{
			a1=ret_count(max, min, c);
		//	printf("%d\n", a1);
			a2=ret_count(min, max, c);
		//	printf("%d\n", a2);
			a3=(a1>a2)?a2:a1;
			printf("%d\n", a3);
		}
	}
	return 0;
}

int gcd(int a, int b)
{
	if(b==0)
		return a;
	else
		return (gcd(b, a%b));
}

int ret_count(int a, int b, int c)
{
	int count=0;
	int x=0;
	int y=0;
	do
	{
		if(x==0)
		{
			x=a;
			count++;
		}
		if(y!=b)
		{
			if(b-y >= x)
			{
				y+=x;
				x=0;
			}
			else
			{
				x=x-(b-y);
				y=b;
			}
			count++;
			if(x==c || y==c) break;
		}
		else
		{
			y=0;
			count++;
			if(b-y >= x)
			{
				y=x;
				x=0;
			}
			else
			{
				x=x-(b-y);
				y=b;
			}
			count++;
		}
	}while(x!=c && y!=c);
	return count;
}
