#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n, l, r;
int board[51][51];
int dist[51][51];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v; // 연합된 좌표 리스트
int sum = 0; // 인구수 합
void bfs(int i, int j) {
	queue<pair<int, int>> q;
	dist[i][j] = 0;
	q.push({ i, j });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] != -1) continue;
			int num = abs(board[nx][ny] - board[x][y]);
			if (num >= l && num <= r) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx, ny });
				sum += board[nx][ny];
				v.push_back({ nx, ny });
			}
		}
	}
}
int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	int cnt = 0; // 인구이동이 일어나는 횟수
	while (1) {
		memset(dist, -1, sizeof(dist)); // 방문배열 초기화
		bool flag = 0; // 인구이동 하는지 flag
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] != -1) continue;
				v.erase(v.begin(), v.end()); // 연합 초기화
				v.push_back({i, j}); 
				sum = board[i][j]; //인구 초기화
				bfs(i, j);
				if (v.size() >= 2) { // 인구 이동을 해야함
					flag = 1;
					int avg = sum / v.size();
					for (auto i : v) {
						int x = i.first;
						int y = i.second;
						board[x][y] = avg; // 인구 이동
					}
				}
			}
		}
		if (!flag) break;
		cnt++;
	}
	cout << cnt;
}