#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,k;
int dp[1002][1002];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	//dp[i][j]=dp[i-1][j]+dp[i-1][j-1]
	
	for (int i = 1; i <= 1000; i++) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}
	cout << dp[n][k];
}