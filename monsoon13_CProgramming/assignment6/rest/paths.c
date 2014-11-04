#include<stdio.h>
#include<stdlib.h>

unsigned one=1;
int **counts;
int total=0;

void print(unsigned **arr, int r, int c){

	int i, j;
	for(i=0; i<r; i++){
		for(j=0; j<c; j++)
			printf("%d ", arr[i][j] );
		printf("\n");
	}
}

void check(unsigned **arr, int r, int c);
void checkex(unsigned **arr, int r, int c, int i);

int main()
{
	int stars, paths, expl, star, j;
	scanf("%d%d%d", &stars, &paths, &expl);
	unsigned **arr;
	arr=(unsigned **)malloc(sizeof(unsigned *)*stars);
	counts=(int **)malloc(stars,sizeof(int *));
	for(i=0; i<stars; i++)
		counts[i]=(int *)calloc(stars, sizeof(int));
	star=stars/32;
	if(stars%32)
		star++;
	int i;
	for(i=0; i<stars; i++)
		arr[i]=(unsigned *)calloc(star,sizeof(unsigned));
//	print(arr,stars,star);
	int from, to, bit;
	for(i=0; i<paths; i++)
	{
		scanf("%d%d", &from, &to);
		to--;
		bit=to%32;
		to=to/32;
		arr[from-1][to]|=(one<<bit);
	}
//	print(arr, stars, star);
	int ways=0, new;
	check(arr, stars, star);
	for(i=0; i<stars; i++){
		ways+=counts[i];
//		printf("%d ", counts[i]);
	}
//	printf("\n");
	printf("%d\n", ways);
	for(i=0; i<expl; i++){
		scanf("%d%d", &from, &to);
		to--;
		bit=to%32;
		to=to/32;
		arr[from -1][to]&=(~(one<<bit));
//		print(arr,stars, star);
		new=ways-counts[from-1];
		checkex(arr, stars, star, from);
		printf("%d\n", new+counts[from-1]);
	}
	return 0;
}

void check(unsigned **arr, int r, int c)
{
	int i, j, k;
	unsigned and;
	int count=0, test=0;
	for(i=0; i<r; i++)
	{
		test=0;
		for(k=0; k<c; k++){
			test+=(__builtin_popcount(arr[i][k]));
		}
		if(test>1){
			for(j=i+1; j<r; j++)
			{
				count=0;
				for(k=0; k<c; k++){
					and=arr[i][k]&arr[j][k];
					count+=__builtin_popcount(and);
				}
				count=((count-1)*(count))/2;
				counts[i][j]+=count;
			}
		}
	}
}

void checkex(unsigned **arr, int r, int c, int i)
{
	int j, k;
	unsigned and;
	int count;
	counts[i-1]=0;
	for(j=0; j<r; j++)
	{
		count=0;
		for(k=0; k<c; k++)
		{
			and=arr[i-1][k]&arr[j][k];
			count+=__builtin_popcount(and);
		}
			count=((count)*(count-1))/2;
			//printf("%d", count);
			counts[i-1]+=count;
			
		
	}
}
