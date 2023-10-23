#include<iostream>
#include <queue>
#include <string.h>
using namespace std;


int board[102][102];
int visited[102][102] = { 0, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int result = 0;//도달 여부 1 가능, 0 불가


void BFS(int i, int j) {
	queue<pair<int, int>> q;
    q.push({i, j});
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{

			int nx = x + dx[dir];
			int ny = y + dy[dir];
            if (board[nx][ny]==3) {
				result = 1;
				return;
			}
			if (nx < 0 || nx>=100 || ny < 0 || ny>=100) continue;
			if (board[nx][ny] == 1|| visited[nx][ny] == 1) continue;
			
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
    result=0;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;


	for (test_case = 1; test_case <= 10; ++test_case)
	{

		int tc;
        cin>>tc;
        int x,y;
        
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				//cin >> board[i][j];
				scanf("%1d", &board[i][j]);
				if (board[i][j] == 2)
				{
					
                    visited[i][j]=1;
                    x=i;
                    y=j;
				}
				
			}
		}


		BFS(x,y);
		cout << "#" << test_case << " " << result << "\n";
		result = 0;
        memset(board, 0, sizeof(board));
        memset(visited, 0, sizeof(visited));
      
    }

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}