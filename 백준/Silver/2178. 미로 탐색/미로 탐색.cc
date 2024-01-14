#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[102][102] = { 0 };
int dist[102][102] = { -1 };
int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '0') board[i][j] = 0;
			else board[i][j] = 1;
			dist[i][j] = 0;
		}
	}

	queue<pair<int, int>> q;

	q.push({ 0,0 });
	dist[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (dist[nx][ny] == 0 && board[nx][ny] == 1) {
					//아직 방문 안 함
					q.push({ nx, ny });
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
		}


	}

	
	//0,0부터 n-1, m-1까지 이동하는 최소 거리
	cout << dist[n - 1][m - 1];
}