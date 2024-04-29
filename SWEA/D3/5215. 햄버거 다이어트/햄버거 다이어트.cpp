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
int item[22][2]; //1부터 n까지 item[i][0] 재료의 맛, item[i][1] 재료의 칼로리
int dp[22][10001]; //[갯수][칼로리] 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int ans = 0;
		int n, l;
		cin >> n >> l;
		for (int i = 1; i <= n; i++) {
			int t, k;
			cin >> t >> k;
			item[i][0] = t;
			item[i][1] = k;
		}
		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = 0;
		for (int i = 1; i <= n; i++) {
			for (int c = 1; c <= l; c++) {
				if (item[i][1] <= c) {
					//최대 칼로리 c를 올려가며 계산
					dp[i][c] = max(dp[i - 1][c], dp[i - 1][c - item[i][1]] + item[i][0]);
					//i번째 item을 넣지않은 경우, i번째 item을 넣은 경우
				}
				else {
					//최대 칼로리 c보다 큰 경우 i번째 item은 넣지 않음
					dp[i][c] = dp[i - 1][c];
				}
			}
		}

		ans = dp[n][l];

		cout << "#" << tc << " " << ans << "\n";
	}
	
}