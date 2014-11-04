#include<stdio.h>

long long int  *merges(long long int *arr, int size);
long long int  *merge(long long int *arr1, long long int *arr2, int size1, int size2);
void print(long long int *arr, int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%lld ", *(arr+i));
	printf("\n");
}



int main()
{
	int tc, i;
	int j;
	long long int *arr;
	int size;
	scanf("%d", &tc);
	for(i=0; i<tc; i++)
	{
		scanf("%d", &size);
		for(j=0; j<size; j++)
			scanf("%lld", arr+j);
		print(arr, size);
		print(merges(arr, size), size);
	}
	return 0;
}

long long int *merges(long long int *arr, int size)
{
	long long int *temp1,*temp2;
	long long int *arrtemp;
	int tempsize1;
	int tempsize2;
	int i;
	if(size>1)
	{
		tempsize1=size/2;
		tempsize2=size-tempsize1;
		printf("%d\n", tempsize1);
		temp1=arr;
		print(temp1, tempsize1);
		temp2=arr+tempsize1;
		print(temp2, tempsize2);
		long long int ptr[size+5];
		return arrtemp=merge(merges(temp1, tempsize1), merges(temp2, tempsize2), tempsize1, tempsize2);
	}
	else
		return arr;
}

long long int *merge(long long int *arr1, long long int *arr2, int size1, int size2)
{
	long long int ptr[size1+size2+5];
	int i=0;
	int s1=size1;
	int s2=size2;
	print(arr1, size1);
	print(arr2, size2);
	printf("Size:%d %d\n", size1, size2);
	if(size1==1 && size2==1)
	{
		if(*arr1>*arr2){*ptr=*arr2; *(ptr+1)=*arr1;}
		else{*ptr=*arr1; *(ptr+1)=*arr2;}
	}
	else
	{
	while(size1!=0 && size2!=0)
	{
		if(*arr1>*arr2)
		{
			printf("Elements2:%lld %lld\n", *arr2, *arr1);
			printf("Elements2:%lld %lld\n", *arr2, *arr1);
			printf("Arr1:%lld\n", *arr1);
			*(ptr+i)=*arr2;
			printf("V(arr)=%lld\n", *ptr);
			++arr2;
			printf("Next2:%lld\n", *arr2);
			printf("Arr1:%lld\n", *arr1);
			i++;
			size2--;
		}
		else
		{
			printf("Elements1:%lld %lld\n", *arr1, *arr2);
			*(ptr+i)=*arr1;
			printf("V(arr)=%lld\n", *ptr);
			++arr1;
			printf("Next1:%lld\n", *arr1);
			printf("Arr2:%lld\n", *arr2);
			i++;
			size1--;
		}
	}
	if(size1==0)
	{
			while(size2!=0)
			{
				*(ptr+i)=*arr2;
				i++;
				arr2++;
				size2--;
			}
	}
	if(size2==0)
	{
			while(size1!=0)
			{
				*(ptr+i)=*arr1;
				i++;
				arr1++;
				size1--;
			}
	}
	}
	print(ptr, s1+s2);
	printf("Merge end\n");
	return ptr;
}
