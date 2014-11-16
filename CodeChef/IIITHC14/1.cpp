#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int checkRow(char arr[35][35], int i, int n);
int checkCol(char arr[35][35], int i, int n);

int arrCheck[35][35];
int main()
{
	int tc, n;
	char arr[35][35];
	SI(tc);
	while(tc--)
	{
		SI(n);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				arrCheck[i][j] = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%s", arr[i]);
		}
		int ans = 1;
		int flag = 0;
		int i, j;
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(arrCheck[i][j] == 0 && arr[i][j] == '1')
				{
//					cout<<i<<j<<" "<<arr[i][j]<<" ";
					flag = checkRow(arr, i, n);
//					cout<<flag<<" ";
					if(not flag)
						flag = checkCol(arr, j, n);
//					cout<<flag<<"\n";
					if(not flag)
						break;
				}
			}
//			cout<<flag<<"\n";
			if(not flag && j != n)
			{
				ans = 0;
				break;
			}
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}

int checkRow(char arr[35][35], int row, int n)
{
	int flag = 0;
	for(int i=0; i<n; i++)
	{
		if(arr[row][i] != '1')
			flag = 1;
		if(flag)
			break;
	}
	if(!flag)
		for(int i=0; i<n; i++)
			arrCheck[row][i] = 1;
	return !flag;
}

int checkCol(char arr[35][35], int col, int n)
{
	int flag = 0;
	for(int i=0; i<n; i++)
	{
		if(arr[i][col] != '1')
			flag = 1;
		if(flag)
			break;
	}
	if(!flag)
		for(int i=0; i<n; i++)
			arrCheck[i][col] = 1;
	return !flag;
}
