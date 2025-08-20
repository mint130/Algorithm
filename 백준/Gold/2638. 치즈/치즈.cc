#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int board[101][101];
bool isAir[101][101];
int n, m;
int cnt = 0; //치즈 갯수
int ans = 0; //걸리는 시간
int dist[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> cheese;
void bfs(int r, int c) {
	dist[r][c] = 0;
	isAir[r][c] = 0;
	queue<pair<int, int>> q;
	q.push({ r, c });
	// 바깥 공기랑만 인접한 것 bfs
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = dx[d] + x;
			int ny = dy[d] + y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] != -1) continue;
			if(!board[nx][ny]){
				// 공기 -> bfs
				isAir[nx][ny] = 1;
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx, ny });
			}
			else {
				//인접한 치즈
				dist[nx][ny] = dist[x][y] + 1;
				cheese.push_back({ nx, ny });
			}
		}
	}

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j]) cnt++;
		}
	}
	while (cnt) {
		// 0, 0에서 bfs
		memset(dist, -1, sizeof(dist)); // 초기화
		memset(isAir, 0, sizeof(isAir));
		cheese.clear();
		bfs(0, 0);
		for (auto i : cheese) {
			int x = i.first;
			int y = i.second;
			int air = 0;
			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (!board[nx][ny] && isAir[nx][ny]) air++;
			}
			if (air >= 2) {
				// c인 치즈 녹임
				board[x][y] = 0;
				cnt--;
			}
		}
		ans++; // 시간 증가
	}
	cout << ans;
}