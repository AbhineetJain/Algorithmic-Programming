#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int nstud, nsub, nq;
char ret[15];
int total[15][100000];

struct student{
	char id[15];
	int m[15];
};
typedef struct student student;

int cmp(const void *a,const void *b)
{
	int *x = (int *) a;
	int *y = (int *) b;
	return *y - *x;
}

void query(int n, student arrs[]);
void disp(char str[], student arrs[]);
void del(char str[], student arrs[]);
char* find(int sub, char studid[], char seq[], student arrs[]);

int main()
{
	scanf("%d%d%d", &nstud, &nsub, &nq);
	int i, j, q;
	student arrs[nstud];
	for(i=0; i<nstud; i++)
	{
		scanf("%s", arrs[i].id);
		for(j=0; j<nsub; j++)
			scanf("%d", &arrs[i].m[j]);
	}
	for(i=0; i<nsub; i++){
		for(j=0; j<nstud; j++)
			total[i][j]=arrs[j].m[i];
	}
/*	for(i=0; i<nsub; i++){
		for(j=0; j<nstud; j++)
			printf("%d ", total[i][j]);
		printf("\n");
	}
*/	for(j=0; j<nsub; j++)
		qsort(total[j], nstud, sizeof(int), cmp);
	for(i=0; i<nsub; i++){
		for(j=0; j<nstud; j++)
			printf("%d ", total[i][j]);
		printf("\n");
	}
	for(i=0; i<nq; i++)
	{
		scanf("%d", &q);
		query(q, arrs);
	for(i=0; i<nsub; i++){
		for(j=0; j<nstud; j++)
			printf("%d ", total[i][j]);
		printf("\n");
	}

	}
	return 0;
}

void query(int n, student arrs[])
{
	char studid[15];
	int subno;
	char seq[5];
	switch(n)
	{
		case 1: 
			scanf("%s", studid);
			disp(studid, arrs);
			break;
		case 2: 
			scanf("%s", studid);
			del(studid, arrs);
			break;
		case 3:
			scanf("%s%d%s", studid, &subno, seq);
			strcpy(studid,find(subno, studid, seq, arrs));
			disp(studid, arrs);
			break;
		default:
			printf("Invalid Query!\n");
			break;
	}
}

void disp(char studid[], student arrs[])
{
	int i, j;
	if(strcmp(studid,"nodisp")){
	for(i=0; i<nstud; i++)
	{
		if(strcmp(studid, arrs[i].id)==0)
		{
			printf("%s ", arrs[i].id);
			for(j=0; j<nsub; j++)
				printf("%d%s", arrs[i].m[j], (j==nsub-1)?"\n":" ");
		}
	}
	}
}

void del(char studid[], student arrs[])
{
	int i, j;
	int *in;
	for(i=0; i<nstud; i++)
	{
		if(strcmp(arrs[i].id,"***")){
			if(strcmp(studid, arrs[i].id)==0)
			{	
				strcpy(arrs[i].id, "***");
				for(j=0; j<nsub; j++)
				{	
					in=bsearch(&(arrs[i].m[j]),total[j],nstud,sizeof(int),cmp);
					
				}
				printf("done\n");
				break;
			}
		}
	}
}


char* find(int sub, char studid[], char seq[], student arrs[])
{
	int i, j, k;
	int marks, markp=-1;
	for(i=0; i<nstud; i++)
	{
		if(strcmp(studid, arrs[i].id)==0)
		{
			marks=arrs[i].m[sub-1];
			break;
		}
	}
	for(i=0; i<nstud; i++)
	{
		j=i;
		if(total[sub-1][i]==marks)
		{
			if(strcmp(seq,"next")==0)
			{
				j=j+1;
				if(i==nstud-1)
				{	printf("last\n");
					strcpy(ret, "nodisp");
				}
				else{
					while(total[sub-1][j]==-1&&j<nstud-1)
						j++;
					if(j==nstud-1&&total[sub-1][j]==-1)
					{	printf("last\n");
						strcpy(ret, "nodisp");
					}
					else
						markp=total[sub-1][j];
				}
			}
			else if(strcmp(seq,"prev")==0)
			{
				j=j-1;
				if(i==0)
				{	printf("first\n");
					strcpy(ret, "nodisp");
				}
				else{
					while(total[sub-1][j]==-1&&j>0)
						j--;
					if(j==0&&total[sub-1][j]==-1)
					{	printf("first\n");
						strcpy(ret, "nodisp");
					}
					else
						markp=total[sub-1][j];
				}
			}
			if(markp!=-1)
			{
				for(k=0; k<nstud; k++)
				{
					if(arrs[k].m[sub-1]==markp)
					{
						strcpy(ret, arrs[k].id);
						break;
					}
				}
			}
			break;
		}
	}
	return ret;
}
