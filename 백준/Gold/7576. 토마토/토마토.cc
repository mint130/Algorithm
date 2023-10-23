#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int board[1002][1002] = {-1, };
//int dist[102][102];
int tomato[1002][1002] = { 0 ,};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };



int main()
{
	int M,N;
	cin >> M >> N;
	queue<pair<int, int>> Q;
	//pair<int, int> tomato;
	for (int i = 0; i <N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) {
				Q.push({ i,j }); 
				
			}
		}

	}
	//board 채움
	//큐에 익은 토마토의 위치를 집어 넣어야 함
	//상하좌우 0이면 1로 바꿈
	// 
//	Q.push({ 0,0 });

	while (!Q.empty())
	{
		

		int x = Q.front().second;
		int y = Q.front().first;
		
	
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			//cout << ny << " " << nx << endl;
			if (nx >= 0 && nx < M && ny >= 0 && ny < N)
			{
				if (board[ny][nx] ==0)
				{
					board[ny][nx] = board[y][x]+1;
					Q.push({ ny,nx });
					
				}
			}
		
			
		}
		
		
	}

	int result = 0;
	//0이 있다면 -1출력
	//1로 끝난다면 0 출력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0) { cout << -1; return 0; }
			else if (board[i][j] > result) result = board[i][j];
		}

		
	}
	
	cout << result-1;
	return 0;


	
	
}