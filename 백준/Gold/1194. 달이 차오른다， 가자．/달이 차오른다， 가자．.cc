#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n, m;
char board[51][51];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dist[51][51][1<<6];
int ans = 987654321;
struct node {
	int x; int y; int key;
};
int main() {
	cin >> n >> m;
	memset(dist, -1, sizeof(dist));
	queue<node> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == '0') {
				q.push({ i, j, 0 });
				dist[i][j][0] = 0;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int key = q.front().key;

		q.pop();
		if (board[x][y] == '1') {
			cout << dist[x][y][key];
			return 0;
		}
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '#') continue; // 못감
			if ((board[nx][ny] == '.' || board[nx][ny]=='0' || board[nx][ny]=='1') && dist[nx][ny][key] == -1) {
				dist[nx][ny][key] = dist[x][y][key] + 1;
				q.push({ nx, ny, key });
			}
			else if (board[nx][ny] >= 'A' && board[nx][ny] <= 'F' && dist[nx][ny][key] == -1) {
				// 문에 닿음->열쇠 있는지 확인
				int num = board[nx][ny] - 'A';
				if ((key & (1 << num))!=0) {
					// 맞는 열쇠가 있어서 문을 열었음
					dist[nx][ny][key] = dist[x][y][key] + 1;
					q.push({ nx, ny, key });
				}
			}
			else if (board[nx][ny] >= 'a' && board[nx][ny] <= 'f' && dist[nx][ny][key] == -1) {
				int num = board[nx][ny] - 'a';
				int nk = key | (1 << num);
				dist[nx][ny][nk] = dist[x][y][key] + 1;
				q.push({ nx, ny, nk });
			}
		}
	}
	cout << -1;
}