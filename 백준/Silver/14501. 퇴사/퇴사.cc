#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string.h>
#include <cstring>

using namespace std;
int arr[17][2]; //arr[i][0]은 상담 시간, arr[i][1]은 이익
int dp[17];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	//n+1은 퇴사
	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;
		arr[i][0] = t;
		arr[i][1] = p;
	}
	for (int i = 0; i < n; i++) {
		//arr[i][0]이 시간
		int t = arr[i][0];
		for (int j = t + i; j <= n; j++) {
			dp[j] = max(dp[j], dp[i] + arr[i][1]);
		}
		
	}
	cout << dp[n];

}