#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;
int n;
int board[26][26];
bool visited[26][26];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ans = 0; //총 단지 수 
vector<int> v; //단지별로 속한 집의 수
void bfs(int r, int c) {
	queue<pair<int, int>> q;
	int cnt = 0; //이 단지 내의 집 수 
	q.push({ r, c });
	visited[r][c] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] && !visited[nx][ny]) {
				//1이면 계속 탐색
				q.push({ nx, ny });
				visited[nx][ny] = 1;
			}
		}
	}
	v.push_back(cnt);

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') board[i][j] = 1;	
			else board[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && board[i][j]) {
				bfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << "\n";
	sort(v.begin(), v.end());
	for (auto i : v) {
		cout << i << "\n";
	}
}