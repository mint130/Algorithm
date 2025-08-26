#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1500002][2];
int dp[1500002]; // i일부터 시작했을 때 얻을 수 있는 최대 이익
int main() {
	cin >> n;
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (int i = 1; i <= n; i++) {
		int t, p;
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = n; i >= 1; i--) {
		if (i + arr[i][0] > n + 1) {
			// 오늘 시작한 상담이 n일 넘어서 끝남 -> 못함
			dp[i] = dp[i + 1]; // 내일부터 시작한 값
		}
		else {
			// 오늘 상담 안 함, 오늘 상담 했을 때 다음 상담 할 수 있는 날의 이익
			dp[i] = max(dp[i + 1], dp[arr[i][0] + i] + arr[i][1]);
		}
	}
	cout << dp[1];
}