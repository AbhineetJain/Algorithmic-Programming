#include<stdio.h>
#include<string.h>

void printrow(char a[][20], int r, int start, int end, int *b, int l);
void printcol(char a[][20], int c, int start, int end, int *b, int l);

int main()
{
	int t, i, j, k, l, m;
	char arr[20][20];
	char input[400];
	int count=0, limit;
	int row, col, pad, len;
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		count=0;
		scanf("%s", input);
		len=strlen(input);
		scanf("%d %d %d", &row, &col, &pad);
		limit=(row*col)-pad;
		for(j=0; j<row; j++)
		{
			for(k=0; k<col; k++)
				arr[j][k]=input[j*col+k];
		}
		for(j=0; count<limit; j++)
		{
			printrow(arr, j, j, col-1-j, &count, limit);
			printcol(arr, col-1-j, j+1, row-1-j, &count, limit);
			printrow(arr, row-1-j, col-2-j, j, &count, limit);
			printcol(arr, j, row-2-j, j+1, &count, limit);
		}
		
		printf("\n");
	}
	return 0;
}

void printrow(char a[][20], int r, int start, int end, int *b, int l)
{
	int i;
	if(start<=end)
	{
		for(i=start; i<=end; i++)
		{	
			if(*b<l)
			{	printf("%c", a[r][i]);
				*b+=1;
			}
		}
	}
	else
	{
		for(i=start; i>=end; i--)
		{
			if(*b<l)
			{
				printf("%c", a[r][i]);
				*b+=1;
			}
		}
	}
}

void printcol(char a[][20], int c, int start, int end, int *b, int l)
{
	int i;
	if(start<=end)
	{
		for(i=start; i<=end; i++)
		{	
			if(*b<l)
			{	printf("%c", a[i][c]);
				*b+=1;
			}
		}
	}
	else
	{
		for(i=start; i>=end; i--)
		{	
			if(*b<l)
			{
				printf("%c", a[i][c]);
				*b+=1;
			}
		}
	}
}
