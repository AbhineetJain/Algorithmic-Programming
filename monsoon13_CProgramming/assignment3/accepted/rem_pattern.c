#include<stdio.h>
#include<string.h>

void init_arr(int a[], int l);
int main()
{
	int t, ls, lp, count[2000]={0}, i=0, flag=0, j, k, l, m;
	char string[2000], pattern[2000];
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		scanf("%s %s", string, pattern);
		ls=strlen(string);
		lp=strlen(pattern);
		init_arr(count, ls);
		for(k=0; k<ls; k++)
		{
			if(string[k]==pattern[0])
			{
				flag=0;
				for(l=k, j=0; j<lp; l++, j++)
				{
					if(string[l]==pattern[j])
					{
						flag++;
						if(flag==lp)
						{
							for(m=0; m<lp; m++)
							{
								count[l-m]=1;
							}
						}
					}
					else
						break;
					
				}
			}
		}
		for(k=0; k<ls; k++)
		{
			if(count[k]==0)
				printf("%c", string[k]);
		}
		printf("\n");
	}
	return 0;
}

void init_arr(int a[], int l)
{
	int i;
	for(i=0; i<l; i++)
		a[i]=0;
}
