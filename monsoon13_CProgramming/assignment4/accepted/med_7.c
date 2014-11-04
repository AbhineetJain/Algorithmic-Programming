#include<stdio.h>

//long long int bsearch(long long int arr[], long long int val, long long int low, long long int high);
//long long int mid;

int main()
{
	long long int n, q;
	long long int query;
	long long int i;
	long long int arr[1000000];
	long long int high, low, mid;
	scanf("%lld", &n);
	for(i=0; i<n; i++)
		scanf("%lld", &arr[i]);
	scanf("%lld", &q);
	for(i=0; i<q; i++)
	{
		scanf("%lld", &query);
		low=0;
		high=n-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(arr[mid]==query)
			{	printf("%lld\n", mid);
				break;
			}
			else if(arr[mid]>query)
				high=mid-1;
			else
				low=mid+1;
		}
		if(low>high) printf("-1\n");
	}
	return 0;
}

/*long long int bsearch(long long int arr[], long long int val, long long int low, long long int high)
{
	 mid=(low+high)/2;
	if(low<=high)
	{
		if(arr[mid]==val)
			return mid;
		else if(arr[mid]>val)
			return bsearch(arr, val, low, mid-1);
		else
			return bsearch(arr, val, mid+1, high);
	}
	else
		return -1;
}*/
