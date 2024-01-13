#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int board[502][502] = { 0 };
int num = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

int BFS(int start_x, int start_y) {
	queue<pair<int, int>> q;
	int cnt = 0; //그림의 넓이를 구하기 위해
	q.push({ start_x,start_y });
	board[start_x][start_y] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (board[nx][ny] == 1) {
					board[nx][ny] = 0;
					q.push({ nx, ny });
				}
			}
		}
	}
	
	return cnt;

}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) {
				num++; //그림의 갯수 증가
				int area = BFS(i, j);
				if (area > max) max = area;
			}
		}
	}
	cout << num << "\n";
	cout << max;
	

}