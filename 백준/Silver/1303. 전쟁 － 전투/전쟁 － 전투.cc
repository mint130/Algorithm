#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int b, w;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char board[101][101];
int bfs(int r, int c) {
	char ch = board[r][c];
	int cnt = 0;
	queue<pair<int, int>> q;
	board[r][c] = 0;
	q.push({ r, c });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (board[nx][ny] == ch) {
				board[nx][ny] = 0;
				q.push({ nx, ny });
			}
		}

	}


	return cnt;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'W') {
				int score = bfs(i, j);
				w += score * score;
			}
			if (board[i][j] == 'B') {
				int score = bfs(i, j);
				b += score * score;
			}
		}
	}
	cout << w << " " << b;
}