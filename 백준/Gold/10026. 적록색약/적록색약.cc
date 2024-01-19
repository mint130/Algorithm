#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int arrR[102][102];
int arrB[102][102];
int arrG[102][102];
int arrRG[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cntR, cntB, cntG, cntRG = 0;

void BFS(int curX, int curY, int arr[][102]) {

	queue<pair<int, int>> q;

	arr[curX][curY] = 0; //지나온 좌표 0으로 표시
	q.push({ curX, curY });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (arr[nx][ny] == 1) {
				arr[nx][ny] = 0; 
				q.push({ nx, ny });
			}
		}
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'R') {
				arrR[i][j] = 1;
				arrB[i][j] = 0;
				arrG[i][j] = 0;
				arrRG[i][j] = 1;
			}
			else if (s[j] == 'B') {
				arrR[i][j] = 0;
				arrB[i][j] = 1;
				arrG[i][j] = 0;
				arrRG[i][j] = 0;
			}
			else if (s[j] == 'G') {
				arrR[i][j] = 0;
				arrB[i][j] = 0;
				arrG[i][j] = 1;
				arrRG[i][j] = 1;
			}
		}
	}
	//입력

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		
			if (arrRG[i][j] == 1) {
				cntRG++;
				BFS(i, j, arrRG);
			}
			if (arrR[i][j] == 1) {
				cntR++;
				BFS(i, j, arrR);
			}
			if (arrG[i][j] == 1) {
				cntG++;
				BFS(i, j, arrG);
			}
			if (arrB[i][j] == 1) {
				cntB++;
				BFS(i, j, arrB);
			}
		}
	}

	int ansRG = cntRG + cntB;
	int ans = cntR + cntG + cntB;
	cout << ans << " " << ansRG;





}