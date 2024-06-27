#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int n;
int board[16][16];
int visit[16][16];
struct dist {
	int sec;
	int x;
	int y;
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		int answer = -1;
		int stx, sty, enx, eny;
		memset(board, 0, sizeof(board));
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		cin >> stx >> sty;
		cin >> enx >> eny;

		queue<dist> q;
		visit[stx][sty] = 1;
		q.push({ 0, stx, sty });
		while (!q.empty()) {
			int curx = q.front().x;
			int cury = q.front().y;
			int sec = q.front().sec;
			q.pop();
			
			if (curx == enx && cury == eny) {
				answer = sec;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = curx + dx[i];
				int ny = cury + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (board[nx][ny] == 1) continue;
				if (board[nx][ny] == 0 && !visit[nx][ny]) {
					visit[nx][ny] = 1;
					q.push({ sec + 1, nx, ny });
				}
				if (board[nx][ny] == 2 && (sec + 1) % 3 == 0 && !visit[nx][ny]) {
					//소용돌이로 진입할 수 있음
					visit[nx][ny] = 1;
					q.push({ sec + 1, nx, ny });

				}
				if (board[nx][ny] == 2 && (sec + 1) % 3 != 0 && !visit[nx][ny]) {
					//기다림
					q.push({ sec + 1, curx, cury });
				}
			}
		}
		cout << "#" << tc << " " << answer << "\n";
	}

}