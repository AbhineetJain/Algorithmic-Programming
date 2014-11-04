#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

unsigned long long one=1;

void set(unsigned long long *j, int index, int bit);
void toggle(unsigned long long *j, int index, int bit);
void reset(unsigned long long *j, int index, int bit);
void c0(unsigned long long *j, int index, int bit);
void c1(unsigned long long *j, int index, int bit);
void convert(unsigned long long *j, int index, int bit, int count);

int main()
{

	int size;
	scanf("%d", &size);
	getchar();
	int n=size;
//	printf("%d\n", size);
	int count=(n/64);
	if((n%64))
		count++;
//	printf("%d\n", count);
	char bits;
	int i;
	unsigned long long *out=(unsigned long long *)malloc(sizeof(unsigned long long)*count);
	*out=0;
	unsigned long long temp=one;
	unsigned long long *j=out;
	for(i=0; i<size; i++){
		if(i==64){
//			printf("Enter\n");
			size=size-64;
			i=0;
			out++;
			*out=0;
			temp=one;
		}
		//scanf("%c", &bits);
		bits=getchar();
		(*out)|=(temp*(bits-'0'));
		temp=temp<<1;
	}
//	for(i=0; i<count; i++)
//		printf("%llu\n", *(j+i));
	int nq, index;
	char q;
	scanf("%d", &nq);
	for(i=0; i<nq; i++){
		getchar();
		scanf("%c", &q);
		scanf("%d", &index);
		int ind=index/64;
		int bit=index%64;
		switch(q){
			case 's':  set(j,ind, bit);
				   break;
			case 'r':  reset(j,ind, bit);
				   break;
			case 't':  toggle(j,ind, bit);
				   break;
			case 'p':  convert(j,ind, bit, count);
				   break;
			case '0':  
				   if(bit==63) ind++;
				   if(index==n-1) printf("0\n");
				   else	c0(j, ind, (bit+1)%64);
			 	   break;
			case '1':  
				   if(bit==63) ind++;
				   if(index==n-1) printf("0\n");
				   else	c1(j, ind, (bit+1)%64);
				   break;
		}
//		printf("%d\n", i);
	}
	return 0;
}


void set(unsigned long long *j, int ind, int bit)
{
	(*(j+ind))=(*(j+ind))|(one<<bit);
}

void reset(unsigned long long *j, int ind, int bit)
{
	(*(j+ind))=(*(j+ind))&(~(one<<bit));
}

void toggle(unsigned long long *j, int ind, int bit)
{
	(*(j+ind))=(*(j+ind))^(one<<bit);
}

void c0(unsigned long long *j, int ind, int bit)
{
	int count=0;
	while(((*(j+ind))&(one<<bit))==0)
	{
		count++;
		bit++;
		if(bit==64)
		{
			ind++;
			bit=0;
		}
	}
	printf("%d\n", count);
}

void c1(unsigned long long *j, int ind, int bit)
{
	int count=0;
//	printf("%d %d\n", ind, bit);
//	printf("%llu\n", one<<bit);
	while(((*(j+ind))&(one<<bit))==(one<<bit))
	{
		count++;
		bit++;
		if(bit==64)
		{
			ind++;
			bit=0;
		}
	}
	printf("%d\n", count);
}

void convert(unsigned long long *j, int ind, int bit, int count)
{
	unsigned long long integer=0;
//	printf("%d\n", ind);
//	printf("%d\n", bit);
	integer=((*(j+ind))>>bit);
//	printf("%llu\n", *(j+ind)>>bit);
	if(64-bit!=64)
	{	
		integer|=((*(j+ind+1))<<(64-bit));
//		printf("%llu\n", (*(j+ind+1))<<(64-bit));
	}

	printf("%llu\n", integer);
}
