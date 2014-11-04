#include<stdio.h>
#include<string.h>

void write(char s[][10], int ind, int i, int j, char str[]);
void sort(char s[][10], int n);
void init_str(char s[][10], int n);
void print(char s[][10], int l);

int main()
{
	char string1[10];
	char string2[10];
	char subs[50][10];
	int t, q, qs;
	int i, j, k, l=0;
	int len1, len2;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		scanf("%s", string1);
		scanf("%s", string2);
		len1=strlen(string1);
		len2=strlen(string2);
		init_str(subs, l);
		l=0;
		for(j=0; j<len1; j++)
		{
			for(k=j; k<len1; k++)
			{
				write(subs,l, j, k, string1);
				l++;
			}
		}
		for(j=0; j<len2; j++)
		{
			for(k=j; k<len2; k++)
			{
				write(subs,l, j, k, string2);
				l++;
			}
		}
		sort(subs, l);
		scanf("%d", &q);
		for(j=0; j<q; j++)
		{
			scanf("%d", &qs);
			printf("%s\n", subs[qs-1]);
		}
	}
	return 0;
}


void write(char s[][10], int ind, int i, int j, char str[])
{
	int p;
	char nstring[10];
	for(p=i; p<=j; p++)
		nstring[p-i]=str[p];
	nstring[p-i]='\0';
	strcpy(s[ind], nstring);
}

void sort(char s[][10], int l)
{
	int j,k;
	char value[10];
	for(j=1; j<l; j++)
	{
	      strcpy(value,s[j]);
	      k=j-1;
	      while(strcmp(s[k],value)>0 && k>=0)
	      {
	            strcpy(s[k+1],s[k]);
	            k--;
	      }
	      strcpy(s[k+1],value);
	}
}

void init_str(char s[][10], int l)
{
	int i;
	for(i=0; i<l; i++)
		s[i][0]='\0';	
}

void print(char s[][10], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%s\n", s[i]);
}
