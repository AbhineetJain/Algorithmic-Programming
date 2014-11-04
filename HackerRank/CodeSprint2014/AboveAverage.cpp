#include<bits/stdc++.h>

using namespace std;

int main()
{
	int tc;
	cin>>tc;
	int n, array[105];
	while(tc--)
	{
		cin>>n;
		int sum=0;
		for(int i=0; i<n; i++)
		{
			cin>>array[i];
			sum+=array[i];
		}
		sum/=n;
		int count=0;
		for(int i=0; i<n; i++)
			if(array[i]>sum)
				count++;
		cout<<count<<endl;
	}
	return 0;
}
