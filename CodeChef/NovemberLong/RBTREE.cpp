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
#define red 1
#define black 0

int even = black, odd = red;

void countNodes(int color, int start, int end);

int main()
{
	int queries;
	SI(queries);
	int start, end;
	char q[3];
	while(queries--)
	{
		scanf("%s", q);
		if(q[1] == 'i')
		{
			even = red; odd = black;
		}
		else
		{
			scanf("%d%d", &start, &end);
			if(end < start)
			{
				int temp = end;
				end = start;
				start = temp;
			}
			if(q[1] == 'r')
			{
				countNodes(red, start, end);
			}
			else	countNodes(black, start, end);
		}
	}
	return 0;
}

void countNodes(int color, int start, int end)
{
	int color_start, color_end;
	int level_start = (int)log2(start);
	int level_end = (int)log2(end);
	if(level_end % 2 == 1) color_end = odd;
	else color_end = even;
	if(level_start % 2 == 1) color_start = odd;
	else color_start = even;
	int color_count = 0;
	while(level_end > level_start)
	{
		if(color_end == color) color_count++;
		end=end/2;
		level_end--;
		color_end = 1 - color_end;
	}
//	printf("end:%d color_count:%d\n", end, color_count);
	if(end != start)
	{
		while(start != end)
		{
			if(color_end == color) color_count++;
			end=end/2;
			color_end = 1 - color_end;
			if(color_start == color) color_count++;
			start=start/2;
			color_start = 1 - color_start;
		}
		if(color_end == color) color_count++;
//		printf("start:%d end:%d color_count:%d\n", start, end, color_count);
	}
	else
		if(color_start == color) color_count++;
	printf("%d\n", color_count);	
}
