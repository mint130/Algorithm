#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//하 우 상 좌
int n, m;
int board[9][9];
int ans = 987654321;
vector<pair<int, int>> cctv;
void check(int x, int y, int dir) {
	dir = dir % 4;
	while(1) {
		int nx = x + dx[dir];
		int ny = y + dy[dir]; //dir방향으로 쭉 나아감
		x = nx;
		y = ny; //현재 x, y 갱신
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;  //범위를 벗어나면 탐색 중단
		if (board[nx][ny] == 6) return; //벽을 만나면 탐색 중단
		if (board[nx][ny] != 0) continue; //한칸 건너뛰고 계속
		board[nx][ny] = -1;
	}
}
void dfs(int k) {
	//k가 cctv의 size가 된다면 모든 cctv를 탐색했으므로 사각지대의 갯수 세기
	if (k == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0) cnt++; //사각지대가 있으면 cnt 추가
			}
		}
		ans = min(cnt, ans);
		return;
	}

	//k번째 cctv의 방향 정할 때
	int x = cctv[k].first;
	int y = cctv[k].second;

	int tmp[9][9];

	for (int dir = 0; dir < 4; dir++) {
		//dir이 현재 방향, dir 4번 상하좌우 모두 실행해봄
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = board[i][j];
			}
		}

		if (board[x][y] == 1) {
			check(x, y, dir);
		}
		else if (board[x][y] == 2) {
			check(x, y, dir);
			check(x, y, dir + 2);
		}
		else if (board[x][y] == 3) {
			check(x, y, dir);
			check(x, y, dir + 1);
		}
		else if (board[x][y] == 4) {
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
		}
		else if (board[x][y] == 5) {
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
			check(x, y, dir + 3);
		}
		dfs(k + 1);
		//초기화
		//return 된 이후=depth를 하나 빠져나온 이후이므로 board를 원래대로 초기화해줌
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = tmp[i][j];
			}
		}

	}

	
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6) {
				cctv.push_back({ i, j }); //위치를 넣음
			}
		}
	}
	
	dfs(0);
	cout << ans;


}