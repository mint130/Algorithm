#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
int n;
long long dp[102][102];
int board[102][102];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!board[i][j]) continue;
			int cnt = board[i][j];
			int x = cnt + i;
			int y = cnt + j;
			if (x < n) dp[x][j] += dp[i][j];
			if (y < n) dp[i][y] += dp[i][j];
		}
	}
	cout << dp[n - 1][n - 1];
}