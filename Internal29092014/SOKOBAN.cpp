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

int rows, cols, targetHits;
void moveLR(pair<int,int>&, vector<string>&, int, int);
//void moveUD(pair<int,int>&, vector<string>&, int);

int main()
{
	LL gameNo=0;
	SI(rows);
	SI(cols);
	while(rows!=0 && cols!=0)
	{
		vector<string> board(20);
		for(int i=0; i<rows; i++)
			cin>>board[i];
		string moves;
		cin>>moves;
		gameNo++;
		int noOfMoves = moves.length();
		pair<int, int> workerPos(-1, -1);
		int noOfTargets=0;
		targetHits=0;
		for(int i=1; i<rows-1; i++)
		{
			for(int j=1; j<cols-1; j++)
			{
				if(board[i][j]=='w' || board[i][j]=='W')
				{
					workerPos.f = i;
					workerPos.s = j;
					if(board[i][j]=='W')
						noOfTargets++;
				}
				else if(board[i][j]=='+' || board[i][j]=='W' || board[i][j]=='B')
				{
					if(board[i][j]=='B')
						targetHits++;
					noOfTargets++;
				}
			}
		}
		for(int i=0; i<noOfMoves; i++)
		{
			if(moves[i]=='U')
				moveLR(workerPos, board, 1, 0);
			else if(moves[i]=='D')
				moveLR(workerPos, board, -1, 0);
			else if(moves[i]=='L')
				moveLR(workerPos, board, 0, 1);
			else
				moveLR(workerPos, board, 0, -1);
			if(targetHits==noOfTargets)
				break;
		}
		printf("Game %lld: ", gameNo);
		if(targetHits==noOfTargets)
			printf("complete\n");
		else
			printf("incomplete\n");
		for(int i=0; i<rows; i++)
			cout<<board[i]<<endl;
		scanf("%d%d", &rows, &cols);
	}
	return 0;
}

void moveLR(pair<int,int>& wp, vector<string> &board, int x, int y) //y=1 for Left, y=-1 for Right
{
	bool isMove=0;
	if(board[wp.f-x][wp.s-y]=='.')
	{
		board[wp.f-x][wp.s-y]='w';
		isMove=1;
	}
	else if(board[wp.f-x][wp.s-y]=='b')
	{
		if(board[wp.f-(2*x)][wp.s-(2*y)]=='.')
		{
			board[wp.f-(2*x)][wp.s-(2*y)]='b';
			isMove=1;
		}
		else if(board[wp.f-(2*x)][wp.s-(2*y)]=='+')
		{
			board[wp.f-(2*x)][wp.s-(2*y)]='B';
			isMove=1;
			targetHits++;
		}
		if(isMove)
			board[wp.f-x][wp.s-y]='w';
	}
	else if(board[wp.f-x][wp.s-y]=='+')
	{
		board[wp.f-x][wp.s-y]='W';
		isMove=1;
	}
	else if(board[wp.f-x][wp.s-y]=='B')
	{
		if(board[wp.f-(2*x)][wp.s-(2*y)]=='.')
		{
			board[wp.f-(2*x)][wp.s-(2*y)]='b';
			isMove=1;
			targetHits--;
		}
		else if(board[wp.f-(2*x)][wp.s-(2*y)]=='+')
		{
			board[wp.f-(2*x)][wp.s-(2*y)]='B';
			isMove=1;
			//targetHits++;
		}
		if(isMove)
			board[wp.f-x][wp.s-y]='W';
	}
	if(isMove)
	{
		if(board[wp.f][wp.s]=='w')
			board[wp.f][wp.s]='.';
		else if(board[wp.f][wp.s]=='W')
		{
			board[wp.f][wp.s]='+';
		//	targetHits--;
		}
		wp.f-=x;
		wp.s-=y;
	}
}

/*void moveUD(pair<int,int>& wp, vector<string> &board, int x) //x=1 for Up, x=-1 for Down
{
	bool isMove=0;
	if(board[wp.f-x][wp.s]=='.')
	{
		board[wp.f-x][wp.s]='w';
		isMove=1;
	}
	else if(board[wp.f-x][wp.s]=='b')
	{
		if(board[wp.f-(2*x)][wp.s]=='.')
		{
			board[wp.f-(2*x)][wp.s]='b';
			isMove=1;
		}
		else if(board[wp.f-(2*x)][wp.s]=='+')
		{
			board[wp.f-(2*x)][wp.s]='B';
			isMove=1;
			targetHits++;
		}
		if(isMove)
			board[wp.f-x][wp.s]='w';
	}
	else if(board[wp.f-x][wp.s]=='+')
	{
		board[wp.f-x][wp.s]='W';
		isMove=1;
	}
	else if(board[wp.f-x][wp.s]=='B')
	{
		if(board[wp.f-(2*x)][wp.s]=='.')
		{
			board[wp.f-(2*x)][wp.s]='b';
			isMove=1;
			targetHits--;
		}
		else if(board[wp.f-(2*x)][wp.s]=='+')
		{
			board[wp.f-(2*x)][wp.s]='B';
			isMove=1;
			//targetHits++;
		}
		if(isMove)
			board[wp.f-x][wp.s]='W';
	}
	if(isMove)
	{
		if(board[wp.f][wp.s]=='w')
			board[wp.f][wp.s]='.';
		else if(board[wp.f][wp.s]=='W')
		{
			board[wp.f][wp.s]='+';
		//	targetHits--;
		}
		wp.f-=x;	
	}
}*/
