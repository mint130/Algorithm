#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
char board[6][6];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int pick[26] = { 0 }; //백트래킹 중(조합을 구하는 중) 방문했는지

int ans = 0;
//0 1 2 3 4 
//5 6 7 8 9
//10 11 12 13 14
//15 16 17 18 19
//20 21 22 23 24

bool bfs() {

	queue<pair<int, int>> q;
	int visit[5][5] = { 0 }; //bfs visit
	int numboard[5][5] = { 0 }; //조합에서 선정된 pick 배열의 idx 가지고 numboard에 옮겨야 함
	memset(visit, 0, sizeof(visit));
	memset(numboard, 0, sizeof(numboard));

	bool first = 1; //처음 들어간 수라면 queue에 넣고 visit 1
	for (int i = 0; i < 25; i++) {
		if (pick[i]) {
			int col = i % 5;
			int row = i / 5;
			numboard[row][col] = 1;
			if (first) {
				first = 0;
				q.push({ row, col });
				visit[row][col] = 1;

			}
		}
	}
	
	int cnt = 1;
	//cnt가 7이 되면 true 반환(인접), 아니라면 false 반환
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (cnt == 7) return true; //인접
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue; //범위를 벗어나면 continue
			if (visit[nx][ny] || !numboard[nx][ny]) continue; //이미 방문했거나 numboard가 0이면 continue
			q.push({ nx, ny });
			visit[nx][ny] = 1;
			cnt++;
		}

	}
	return false;
}
bool four() {
	int cnt = 0;
	//s의 갯수가 4개보다 큰지
	for (int i = 0; i < 25; i++) {
		int col, row = 0;
		row = i / 5;
		col = i % 5;
		if (board[row][col] == 'S' && pick[i] == 1) cnt++;
		
	}
	if (cnt >= 4) return true;
	else return false;
	
}
void dfs(int cnt, int idx) {
	//25개 중 7개 뽑음, 중복 x, 조합(idx가 있는 경우=고른 수열이 오른차 순이어야 함)
	//그 중에서 s의 갯수가 4보다 큰 경우에만 인접한지 확인

	if (cnt == 7) {
		if (bfs() && four()) ans++; //s의 갯수가 4보다 크고 인접하다면 ans
		return;
		//ans++;
	}

	for (int i = idx; i < 25; i++) {
		if (!pick[i]) {
			pick[i] = 1;
			dfs(cnt + 1, i);
			pick[i] = 0;
		}
	}
	//visit에는 뽑힌 수들이 true, 여기서 이다솜파의 수가 4이상이어야 함
}

int main() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}
	
	dfs(0, 0);
	cout << ans;
}