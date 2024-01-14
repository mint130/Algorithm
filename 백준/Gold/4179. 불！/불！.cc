#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int r, c;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char board[1002][1002];
int dist[1002][1002]={0}; //지훈이의 이동거리
int fire[1002][1002]={0}; //불의 이동거리
queue<pair<int, int>> q; //지훈이의 위치
queue<pair<int, int>> q2; //불의 위치
int main() {
	//행, 열 입력받음
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			board[i][j]=s[j];
			if (board[i][j] == 'J') {
				q.push({ i,j });
				dist[i][j] = 1;
			}
			if (board[i][j] == 'F') {
				q2.push({ i, j });
				fire[i][j] = 1;
			}
		}
	}
	while (!q2.empty()) {
		int x = q2.front().first;
		int y = q2.front().second;
		q2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (board[nx][ny] != '#' && fire[nx][ny]==0) {
					q2.push({ nx, ny });
					fire[nx][ny] = fire[x][y] + 1;
				}
			}
		}
	}
	

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				//범위를 벗어나면 탈출
				cout << dist[x][y];
				return 0;
			}
			if (board[nx][ny] != '#' && dist[nx][ny] == 0) {
				if (fire[nx][ny] != 0 && fire[nx][ny] > dist[x][y] + 1) {
					q.push({ nx, ny });
					dist[nx][ny] = dist[x][y] + 1;
				}
				else if(fire[nx][ny] == 0) {
					q.push({ nx, ny });
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
			
		}

	}
	
	cout << "IMPOSSIBLE";
	
}