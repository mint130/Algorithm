#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int r, c, t;
int board[51][51];
int tx, bx; // 공기청정기 위치
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
// 이동
void top() {
	// 밑으로
	for (int i = tx - 1; i >= 1; i--) {
		board[i][0] = board[i - 1][0];
	}
	// <-
	for (int i = 0; i < c - 1; i++) {
		board[0][i] = board[0][i + 1];
	}
	// 위로 
	for (int i = 0; i <= tx - 1; i++) {
		board[i][c - 1] = board[i + 1][c - 1];
	}
	// ->
	for (int i = c - 1; i >= 1; i--) {
		board[tx][i] = board[tx][i - 1];
	}
	board[tx][1] = 0;
}
void bottom() {
	// 위로
	for (int i = bx + 1; i < r - 1; i++) {
		board[i][0] = board[i + 1][0];
	}
	// <-
	for (int i = 0; i < c - 1; i++) {
		board[r - 1][i] = board[r - 1][i + 1];
	}
	// 아래로
	for (int i = r - 1; i >= bx + 1; i--) {
		board[i][c - 1] = board[i - 1][c - 1];
	}
	// ->
	for (int i = c - 1; i >= 1; i--) {
		board[bx][i] = board[bx][i - 1];
	}

	board[bx][1] = 0;

}
int main() {
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) continue;
			if (board[i][j] == -1) {
				if (tx == 0) tx = i;
				else bx = i;
			}
		}
	}
	while (t--) {
		int tmp[51][51]; // 확산된 양 저장
		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i < r;i++) {
			for (int j = 0; j < c; j++) {
				if (board[i][j] > 0) {
					int num = board[i][j];
					int cnt = 0;
					for (int dir = 0; dir < 4; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
						if (board[nx][ny] == -1) continue;
						tmp[nx][ny] += num / 5; // 확산된 양 저장
						cnt++;
					}
					if (cnt != 0) board[i][j] -= num / 5 * cnt; // 현재 위치의 미세먼지 값 갱신
				}
			}
		}
		// 미세먼지 합침
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (board[i][j] == -1) continue;
				board[i][j] += tmp[i][j];
			}
		}
		
		// 공기 청정기 작동
		top();
		bottom();
		
	}
	// 미세먼지 합
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] != -1) sum += board[i][j];
		}
	}
	cout << sum;
}