#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int ans[1001];
int dp[201][201];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> dp[i][j];
		}
	}
	for (int i = 0;i < m;i++) {
		cin >> ans[i];
	}
	// 플로이드 
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (dp[i][j] == 0) {
				if (i != j) dp[i][j] = 987654321;
			}
		}
	}
	
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
			}
		}
	}
	
	
	for (int i = 0;i < m-1;i++) {
		int st = ans[i];
		int en = ans[i + 1];
		if (dp[st][en] == 987654321) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}