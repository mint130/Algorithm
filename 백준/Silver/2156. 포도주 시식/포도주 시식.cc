#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int arr[10002]; //i번째 포도주의 양 
int dp[10002]; //i번째에서 최대로 마시는 포도주의 양
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	//dp[3]은 6+10(dp[2])에 3번째 잔은 안마시거나
	//6(dp[1])에 3번째 잔을 마시거나(arr[3])
	//1번째 이전까지의 dp(dp[0]) + 2번째, 3번째 잔을 마시거나 (arr[2]+arr[3])
	//dp[3]=max(dp[2], dp[1]+arr[3], dp[0]+arr[2]+arr[3])

	//dp[k]=max({dp[k-1], dp[k-2]+arr[k], dp[k-3]+arr[k-1]+arr[k]})

	for (int i = 3; i <= n; i++) {
		dp[i] = max({ dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i] });
	}
	cout << dp[n];
}