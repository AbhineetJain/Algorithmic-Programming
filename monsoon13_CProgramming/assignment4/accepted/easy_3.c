#include<stdio.h>
#include<string.h>

int check(char board[][10]);
char str1[10]="WBWBWBWB";
char str2[10]="BWBWBWBW";

int main()
{
	long long int tc, i;
	char board[10][10];
	int j;
	scanf("%lld", &tc);
	for(i=0; i<tc; i++)
	{
		for(j=0; j<8; j++)
			scanf("%s", board[j]);
		if(check(board))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

int check(char board[][10])
{
	int count=0;
	int i;
	for(i=0; i<8; i++)
	{
		if(strcmp(board[i],str1)==0 || strcmp(board[i],str2)==0)
		{
		//	printf("%d %d\n", strcmp(board[i], str1), strcmp(board[i],str2));
		//	printf("%s\n", board[i]);
		//	printf("Check%d\n", i);
			count++;
		}
	}
	if(count==8)
		return 1;
	else
		return 0;
}
