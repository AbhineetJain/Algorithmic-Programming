#include<stdio.h>
#include<string.h>

int write(char s[][110], int ind, int i, int j, char str[]);
void sort(char s[][110], int n);
void init_str(char s[][110], int n);
void print(char s[][110], int n);

int main()
{
	char string[110];
	char subs[10000][110];
	int t, q, qs[1000];
	int i, j, k, l=0;
	int len;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		scanf("%s", string);
		len=strlen(string);
		init_str(subs, l);
		l=0;
		for(j=0; j<len; j++)
		{
			for(k=j; k<len; k++)
			{
				if(write(subs,l, j, k, string)==0)
					l++;
			}
		}
		print(subs, l);
		sort(subs, l);
		print(subs, l);
		scanf("%d", &q);
		for(j=0; j<q; j++)
			scanf("%d", &qs[j]);
		for(j=0; j<q; j++)
		{
			printf("%s\n", subs[qs[j]-1]);
		}
	}
	return 0;
}


int write(char s[][110], int ind, int i, int j, char str[])
{
	int p, flag=0;
	char nstring[110];
	for(p=i; p<=j; p++)
		nstring[p-i]=str[p];
	nstring[p-i]='\0';
	for(p=0; p<ind; p++)
	{
		if(strcmp(nstring, s[p])==0)
			flag++;
	}
	if(flag==0)
		strcpy(s[ind], nstring);
	return flag;
}

void sort(char s[][110], int l)
{
	int j,k;
	char value[110];
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

void init_str(char s[][110], int l)
{
	int i;
	for(i=0; i<l; i++)
		s[i][0]='\0';	
}

void print(char s[][110], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%s\n", s[i]);
}
