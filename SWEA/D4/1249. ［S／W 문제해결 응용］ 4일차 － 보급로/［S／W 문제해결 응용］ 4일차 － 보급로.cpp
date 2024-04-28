#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string.h>
#include <cstring>

using namespace std;
int board[101][101];
int dist[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;

		//출발은 0, 0 
		//도착은 n-1, n-1
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;

			for (int j = 0; j < n; j++) {
				int k = s[j] - '0';
				board[i][j] = k;
                dist[i][j]=-1;
			}
		}

		queue<pair<int, int>> q;
		dist[0][0] = 0;
		q.push({ 0,0 });

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = dx[i] + x;
				int ny = dy[i] + y;
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (dist[nx][ny] == -1 || (dist[nx][ny] != -1 && dist[x][y] + board[nx][ny] < dist[nx][ny])) {
				
					dist[nx][ny] = dist[x][y] + board[nx][ny];
					q.push({ nx, ny });
				}

			}
		}

		cout << "#" << tc << " " << dist[n-1][n-1] << "\n";
		memset(board, 0, sizeof(board));

	}
	
}