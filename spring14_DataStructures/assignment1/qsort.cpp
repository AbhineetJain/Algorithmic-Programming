#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	int i, n, arr[100003];
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	return 0;
}
