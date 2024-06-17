#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;
int n;
int board[18][18];
int dp[18][18][3]; //0은 가로 1은 세로 2는 대각선
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	dp[0][1][0] = 1;
	//1이면 벽
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) continue;
			if (board[i][j]) continue; //벽
			if (j + 1 < n && !board[i][j + 1]) {
				//가로가 비어있음
				dp[i][j + 1][0] += dp[i][j][0];
				dp[i][j + 1][0] += dp[i][j][2];
			}
			if (i + 1 < n && !board[i + 1][j]) {
				//세로가 비어있음
				dp[i + 1][j][1] += dp[i][j][1];
				dp[i + 1][j][1] += dp[i][j][2];
			}
			if (i + 1 < n && j + 1 < n && !board[i + 1][j + 1] && !board[i + 1][j] && !board[i][j + 1]) {
				dp[i + 1][j + 1][2] += dp[i][j][0];
				dp[i + 1][j + 1][2] += dp[i][j][1];
				dp[i + 1][j + 1][2] += dp[i][j][2];
			}

			
		}
	}

	cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
}