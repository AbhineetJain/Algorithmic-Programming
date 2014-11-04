#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void count_sort(char **a, int size, int);
void print(char **a, int size);
//void radix(int a[], int size);
char *strrev(char *s)
{
	int i, j;
	for(i=0, j=strlen(s)-1; i<j; i++, j-- )
		s[i]=s[j]+s[i]-(s[j]=s[i]);
	return s;
}

int main()
{
     int size, k, max, i;
     char **ip=NULL;
     int j, tc;
     scanf("%d", &tc);
     for(j=0; j<tc; j++)
     {
	scanf("%d", &size);
	max=0;
	ip=(char **)malloc(sizeof(char *)*size);
	for(i=0; i<size; i++)
	{
		ip[i]=(char *)malloc(sizeof(char)*50);
		scanf("%s", ip[i]);
		if(strlen(ip[i])>max) max=strlen(ip[i]);
		ip[i]=strrev(ip[i]);
	}
	scanf("%d", &k);
	for(i=0; i<size; i++)
	{
		while(strlen(ip[i])!=max) ip[i][strlen(ip[i])]='0';
	}
//	print(ip, size);
//	printf("%d %d\n", max, k);
	max=(max-(max%(k+1)));
	for(i=0; i<max; i++)
	{
//		printf("%d:\n", i);
		count_sort(ip, size, i);
		if(i%(k+1)==k) print(ip, size);
	}
     }
     return 0;
}

void print(char **a, int size)
{
	int i, j;
	for(i=0; i<size; i++)
	{
		a[i]=strrev(a[i]);
		for(j=0; a[i][j]!='\0'; j++)
		{
			if(a[i][j]!='0')
				break;
		}
		if(a[i][j]=='\0') printf("0 ");
		//a[i]=&a[i]a[j];
		else{
			for(; a[i][j]!='\0'; j++)
				printf("%c", a[i][j]);
			if(i!=size-1)
				printf(" ");
			a[i]=strrev(a[i]);
		}
	}
	printf("\n");
}

void count_sort(char **a, int size, int m)
{
	char **b=NULL;
	int *c=NULL;
	int i;
	c=(int *)calloc(10, sizeof(int));
	b=(char **)malloc(sizeof(char *)*size);
	for(i=0; i<size; i++)
		b[i]=(char *)malloc(sizeof(char)*50);
	for(i=0; i<size; i++)
		c[a[i][m]-'0'] = c[a[i][m]-'0']+1;
//	for(i=0; i<10; i++) printf("%d ", c[i]);
//	printf("\n");
//	print(c, max);
	for(i=1; i<=9; i++)
		c[i] = c[i] + c[i-1];
//	print(c, max);
//	for(i=0; i<10; i++) printf("%d ", c[i]);
//	printf("\n");
	for(i=size-1; i>=0; i--)
	{
//		printf("i:%d %d\n", c[a[i][m]-'0'], a[i][m]-'0');
//		printf("%s\n", a[i]);
		strcpy(b[c[a[i][m]-'0']-1], a[i]);
		c[a[i][m]-'0']--;
	}
	for(i=0; i<size; i++)
		strcpy(a[i], b[i]);
}

