#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int dp[31][31];
int main() {
	for (int i = 1; i <= 30; i++) {
		dp[i][1] = 1;
		dp[i][i] = 1;
	}
	for (int i = 2; i <= 30; i++) {
		for (int j = 2; j <= 30; j++) {
			if (i == j) continue;
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	
	int r, c, w;
	cin >> r >> c >> w;
	int ans = 0;
	for (int i = r; i < r + w; i++) {
		for (int j = c; j < c + w; j++) {
			if (i - r >= j - c) {
				ans += dp[i][j];
			}
			
		}
	}
	cout << ans;

}