#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int arr[101]; //주어진 숫자
long long dp[101][21]; //dp[i][j]는 i번째 왔을 때 합 j를 만들 수 있는 경우의 수

int main() {
	int n;
	cin >> n;

	//arr[n-1]이 마지막 합
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0][arr[0]] = 1;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 0; j <= 20; j++) {
			//j는 합
			//직전 인덱스까지 만들어진 합의 경우의 수 dp[i-1][j], 존재하지 않으면 0
			if (dp[i - 1][j] != 0) {
				//존재
				if (j + arr[i] <= 20 && j + arr[i] >= 0) {
					//직전 인덱스까지 만들어진 합 j+현재 인덱스 값이 0~20 사이면 
					dp[i][j + arr[i]] += dp[i - 1][j];
					
				}
				if (j - arr[i] <= 20 && j - arr[i] >= 0) {
					dp[i][j - arr[i]] += dp[i - 1][j];

				}
			}
		}
	}
	
	cout << dp[n - 2][arr[n - 1]];
}