#include <iostream>
using namespace std;
int dp[12];
int n, T;
int main() {
	cin >> T;
	dp[1] = 1;
	dp[2] = dp[1] + 1;
	dp[3] = dp[1] + dp[2] + 1;
	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
	for (int tc = 0; tc < T; tc++) {
		cin >> n;
		cout << dp[n] << "\n";
	}
}