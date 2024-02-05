#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[100002];
int dp[100002]; //0부터i번째 수까지의 합 dp[i]에 저장
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}
	for (int k = 0; k < m; k++) {
		int i, j;
		int sum = 0;
		cin >> i >> j;
		sum = dp[j] - dp[i-1];

		//i번째 수부터 j번째 수까지의 합 
		cout << sum << "\n";
	}

}