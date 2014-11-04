#include<stdio.h>
#include<string.h>


int main()
{
	char string[2000][2000], rhyme[4][2000];
	int t, c, i, j, k, max, lines, flag, len[2000], scheme[2000];
	scanf("%d", &t);
	getchar();
	for(i=0; i<t; i++)
	{
		j=0;
		k=0;
		while((c=getchar())!='#')
		{
			if(c!='\n')
			{
				string[j][k]=c;
				j++;
			}
			else
			{	
				len[k]=j;
				k++;
				j=0;
			}
		}
		getchar();
		len[k]=j;
		lines=k+1;
		for(k=0; k<lines; k++)
		{	
			rhyme[0][k]=string[len[k]-2][k];
			rhyme[1][k]=string[len[k]-1][k];
		}
		scheme[0]=65;
		max=65;
		for(k=1; k<lines; k++)
		{
			flag=0;
			for(j=0; j<k; j++)
			{
				if(rhyme[0][j]==rhyme[0][k]&&rhyme[1][j]==rhyme[1][k])
				{	
					scheme[k]=scheme[j];
					flag=1;
					break;
				}
			}
			if(flag!=1)
			{
				scheme[k]=max+1;
				max=scheme[k];
			}
		}
		for(k=0; k<lines; k++)
			printf("%c", scheme[k]);
		printf("\n");
	}
	return 0;
}
