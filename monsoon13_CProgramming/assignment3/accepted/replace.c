#include<stdio.h>
#include<string.h>

void init_arr(int a[], int l);
int main()
{
	int t, ls, lp, count[10002], i=0, j, k, l, m;
	char string[10002], pattern[1002];
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		scanf("%s %s", string, pattern);
		ls=strlen(string);
		lp=strlen(pattern);
		init_arr(count, ls);
		for(k=0; k<ls; k++)
		{
			if((string[k]==pattern[0]||string[k]=='?'))
			{
				for(l=k, j=0; j<lp; l++, j++)
				{
					if(string[l]==pattern[j]||string[l]=='?')
						count[l]++;
					else
					{
						for(m=l-1; m>=k; m--)
							count[m]--;
						break;
					}
				}
			}
		}
		for(k=0; k<ls; k++)
		{
			if(count[k]>0)
			{
				for(l=k,j=0; j<lp; j++, l++)
				{	
					count[l]--;
					string[l]=pattern[j];
				}
			}
			else if(string[k]=='?')
				string[k]='*';

		}
		for(k=0; k<ls; k++)
			printf("%c", string[k]);
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
