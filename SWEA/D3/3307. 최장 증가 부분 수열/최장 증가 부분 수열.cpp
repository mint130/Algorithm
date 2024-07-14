#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T;
int arr[1001];
int dp[1001]; //i까지 왔을 때 최장 수열의 길이 저장
int ans;
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		fill(arr, arr + 1001, 0);
		int n;
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++) {
			dp[i] = 1;
			for (int j = i - 1; j >= 1; j--) {
				if (arr[i] > arr[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		cout << "#" << tc << " " << ans << "\n";
	}
}