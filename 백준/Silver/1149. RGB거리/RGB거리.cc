#include <iostream>

using namespace std;

int house[1002][4]; //집을 빨강 초록 파랑으로 칠하는 비용
int d[1002][4]; //i번째 집을 j색으로 칠했을 때 최소값
int dp[1002]; //i번째 집을 칠할 때 드는 최소값
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> house[i][j];
		}
	}
	//인접한 집은 색이 달라야 함
	d[1][1] = house[1][1];
	d[1][2] = house[1][2];
	d[1][3] = house[1][3];
	dp[1] = min(d[1][1], d[1][2]);
	dp[1] = min(dp[1], d[1][3]);
	for (int i = 2; i <= n; i++) {
		d[i][1] = min(d[i - 1][2], d[i - 1][3]) + house[i][1];
		d[i][2] = min(d[i - 1][1], d[i - 1][3]) + house[i][2];
		d[i][3] = min(d[i - 1][1], d[i - 1][2]) + house[i][3];
		int cost = 0;
		cost = min(d[i][1], d[i][2]);
		cost = min(cost, d[i][3]);
		dp[i] = cost;
	}
	cout << dp[n];
}