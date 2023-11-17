#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int board[101][101];
int visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int groupCnt = 0;
//왼쪽 아래 꼭짓점 x y 좌표
//오른쪽 위 꼭짓점 x y 좌표
vector<int> group;

int m, n, k;

int BFS(int r, int c)
{
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ r,c });
	board[r][c] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (board[nx][ny] == 0) {
					board[nx][ny] = 1;
					q.push({ nx, ny });
					
				}
			}
		}
	}
	return cnt;

}

int main() {
	cin >> n >> m >> k;
	//m 가로 n 세로 k 사각형

	for (int i = 0; i < k; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int c = x1; c < x2; c++)
		{
			for (int r = y1; r < y2; r++)
			{
				board[r][c] = 1;
			
			}
		}
	}

	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
			{
				groupCnt++;
				group.push_back(BFS(i, j));
				
			}
		}
	}
	sort(group.begin(), group.end());
	cout << groupCnt << endl;
	for (int i = 0; i < group.size(); i++) {
		cout << group[i] << " ";
	}
}