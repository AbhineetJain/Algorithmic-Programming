#include<stdio.h>
#include<stdlib.h>

//Check for n<=size if not accepted or Segmentation Fault

struct hash{
	int h1;
	int h2;
};
typedef struct hash hash;

int *table=NULL;
hash *function=NULL;
int size, n, count=0;

int insert(int num, int h1, int h2);
void print(int size);
void printfunc(int size);

int main()
{
	int tc, i;
	scanf("%d", &tc);
	for(i=0; i<tc; i++)
	{
		int j, h1, h2, track=0;
		count=0;
		scanf("%d%d", &n, &size);
		table = (int *)malloc(sizeof(int)*size);
		function = (hash *)malloc(sizeof(hash)*(size+1));
		for(j=1; j<=n; j++)
		{
			scanf("%d%d", &h1, &h2);
			function[j].h1 = h1;
			function[j].h2 = h2;
			track+=insert(j, h1, h2);
//			print(size);
		}
//		printf("%d\n", track);
		if(track) printf("rehash necessary\n");
		else printf("successful hashing\n");
	}
	return 0;
}


int insert(int num, int h1, int h2)
{
	int place, temp=0, temp2;
	if(table[h1]==0) table[h1] = num;
	else if(table[h2]==0) table[h2] = num;
	else{
		temp = table[h1];
		table[h1] = num;
		place = h1;
		while(temp!=0 && count!=n)
		{
//			print(size);
			if(place == function[temp].h1){
				place = function[temp].h2;
				temp2 = table[place];
				table[place] = temp;
				temp = temp2;
			}
			else if(place == function[temp].h2){
				place = function[temp].h1;
				temp2 = table[place];
				table[place] = temp;
				temp = temp2;
			}
			count++;
		}
	}
	if(temp) return 1;
	else return 0;
}

void print(int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d ", table[i]);
	printf("\n");
}

void printfunc(int size)
{
	int i;
	for(i=1; i<=size; i++)
		printf("%d %d\n", function[i].h1, function[i].h2);
}
