#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int m, n, h; //m은 가로, n은 세로, h는 높이

int dx[6] = { 0, 0, 1, 0, -1, 0 };
int dy[6] = { 0, 0, 0, 1, 0, -1 };
int dz[6] = { 1, -1, 0, 0, 0, 0 };
int arr[102][102][102];
queue<tuple<int, int, int>> q;

int main() {
	cin >> m >> n >> h;
	
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[k][i][j];
				if (arr[k][i][j] == 1) {
					q.push(make_tuple(k, i, j));
				}
			}
		}
	}

	while (!q.empty()) {
		int x = get<1>(q.front());
		int y = get<2>(q.front());
		int z = get<0>(q.front());

		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			int nz = dz[i] + z;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (arr[nz][nx][ny] == 0) {
				arr[nz][nx][ny] = arr[z][x][y] + 1;
				q.push(make_tuple(nz, nx, ny));
			}
		}
	}



	//0이 있으면 중단하고 -1 출력, 현재 ans보다 큰 값이 있으면 ans 변경
	int ans = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[k][i][j] == 0) {
					cout << -1;
					return 0;
				}
				if (arr[k][i][j] > ans) ans = arr[k][i][j];
			}
		}
	}
	cout << ans-1;
}