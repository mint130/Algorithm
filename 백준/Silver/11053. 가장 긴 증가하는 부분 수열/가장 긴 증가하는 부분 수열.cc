#include <iostream>
using namespace std;

int n;
int arr[1002];
int dp[1002];
int ans = 0;
int main() {
	cin >> n;
	//가장 긴 증가하는 부분 수열
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			//dp[i]는 i번째 수 까지 왔을 때 가질 수 있는 가장 긴 부분 수열
			//dp[i]를 찾는 방법: arr[i]보다 작은 수들 중에 가장 긴 부분 수열을 가진 dp값+1
			if (arr[i] > arr[j]) {
				//dp[j]값중에 가장 큰 값+1과 기존 dp[i]비교
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
		
	}
	cout << ans;
}