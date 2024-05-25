#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int board[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, k; //n세로 m가로
int bfs(int r, int c) {
	board[r][c] = 0;
	int cnt = 0;
	queue < pair<int, int>> q;
	q.push({ r, c });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny]) {
				board[nx][ny] = 0;
				q.push({ nx, ny });
			}
		}

	}
	return cnt;
}
int main() {
	int ans = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		board[r-1][c-1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j]) {
				ans = max(ans, bfs(i, j));
			}
		}
	}
	cout << ans;
}
