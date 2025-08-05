#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int board[501][501];
bool visited[501][501];
int ans;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void dfs(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		ans = max(sum, ans);
		return;
	}
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (visited[nx][ny]) continue;
		visited[nx][ny] = 1;
		dfs(nx, ny, cnt + 1, sum + board[nx][ny]);
		visited[nx][ny] = 0;
	}
	
}
// 0 1 2 3 4
// 5 6 7 8 9
// 10 11 12 13 14
// ㅜ 모양
void down() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int sum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1];
			ans = max(sum, ans);
		}
	}
}
// ㅏ 모양
void right() {
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int sum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1];
			ans = max(sum, ans);
		}
	}
}
// ㅗ 모양
void up() {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m - 2; j++) {
			int sum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i - 1][j + 1];
			ans = max(sum, ans);
		}
	}

}
// ㅓ 모양
void left() {
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			int sum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j - 1];
			ans = max(sum, ans);
		}
	}

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	down();
	up();
	left();
	right();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) continue;
			visited[i][j] = 1;
			dfs(i, j, 1, board[i][j]);
			visited[i][j] = 0;
		}
	}
	cout << ans;
}