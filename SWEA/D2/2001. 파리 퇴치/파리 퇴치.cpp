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
int board[16][16];
int m, n;
int solve(int r, int c) {
	int sum = 0;
	for (int i = r; i <= r + m - 1; i++) {
		for (int j = c; j <= c + m - 1; j++) {
			sum += board[i][j];
		}
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int answer = 0;
		
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		for (int i = 0; i <= n - m; i++) {
			for (int j = 0; j <= n - m; j++) {
				//i, j가 좌표, i+m-1, j+m-1까지
				int sum = 0;
				sum = solve(i, j);
				answer = max(answer, sum);
			}
		}
		memset(board, 0, sizeof(board));
		cout << "#" << tc << " " << answer << "\n";
	}
}