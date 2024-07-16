#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
int dp[100001];

int main() {
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 2;
	dp[5] = 1;
	for (int i = 6; i <= n; i++) {
		if (dp[i - 2] == 0) {
			dp[i] = dp[i - 5] + 1;
		}
		else if (dp[i - 5] == 0) {
			dp[i] = dp[i - 2] + 1;
		}
		else {
			dp[i] = min(dp[i - 5] + 1, dp[i - 2] + 1);
		}
	}
	if (n == 1 || n == 3) cout << -1;
	else cout << dp[n];
}