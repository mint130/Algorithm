#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[1001][3]; //i번째 집이 r,g,b일때 i번째집까지 칠하는 비용 최솟값
int color[1001][3]; //i번째 집을 r,g,b로 칠하는 비용
int ans = 987654321;
int main() {
	cin >> n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	//집을 칠하는 비용 입력 받음, 초기화
	for (int i = 1;i <= n;i++) {
		cin >> color[i][0] >> color[i][1] >> color[i][2];
	}


	for (int c = 0;c < 3;c++) {
		for (int i = 1;i <= 2;i++) {
			//초기화
			dp[i][0] = dp[i][1] = dp[i][2] = 987654321;
		}
		dp[1][c] = color[1][c]; //가장 처음 집 색깔 

		//i-1번째와 겹치지 않게
		for (int i = 2;i <= n;i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
		}

		//첫번째 집과 마지막 집이 겹치지 않게
		if (c == 0) ans = min({ ans, dp[n][1], dp[n][2] });
		else if (c == 1) ans = min({ ans, dp[n][0], dp[n][2] });
		else ans = min({ ans, dp[n][0], dp[n][1] });
	}

	cout << ans;


}