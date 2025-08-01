#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
char board[12][6];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dist[12][6];
int num = 0;
vector<pair<int, int>> v[5];
void bfs(int i, int j, char c, int num) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	dist[i][j] = 0;
	v[num].push_back({ i, j });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
			if (dist[nx][ny] != -1) continue;
			if (board[nx][ny] != c) continue;
			// 글자가 c랑 같으면 추가
			q.push({ nx, ny });
			dist[nx][ny] = dist[x][y] + 1;
			v[num].push_back({ nx, ny });
		}
	}
	
}
void init() {
	for (int i = 0; i < 5; i++) {
		v[i].erase(v[i].begin(), v[i].end());
	}
}
int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
	}
	int cnt = 0;
	while (1) {
		memset(dist, -1, sizeof(dist));
		bool flag = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] == '.') continue;
				if (dist[i][j] != -1) continue;
				init();
				char c = board[i][j]; // 글자 c
				if (c == 'R') num = 0;
				else if (c == 'G') num = 1;
				else if (c == 'B') num = 2;
				else if (c == 'P') num = 3;
				else if (c == 'Y') num = 4;
				bfs(i, j, c, num);
				if (v[num].size() >= 4) {
					// 연쇄 일어남
					flag = 1;
					for (auto i : v[num]) {
						int x = i.first;
						int y = i.second;
						board[x][y] = '.';
					}
				}
			}
		}

		// 아래로 내려줌
		for (int i = 0; i < 6; i++) {
			for (int j = 11; j >= 1; j--) {
				if (board[j][i] == '.') {
					for (int k = j - 1; k >= 0; k--) {
						if (board[k][i] != '.') {
							board[j][i] = board[k][i];
							board[k][i] = '.';
							break;
						}
					}
				}

			}

		}
		
		if (!flag) break;
		cnt++;
	}
	
	cout << cnt;
	
}