#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int arr[1001];
int dp[1001];
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	//dp[1] = arr[1];
	for (int i = 1; i <= n; i++) {
		dp[i] = arr[i];
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[j] + arr[i], dp[i]);
			}
		}
		
	}

	cout << *max_element(dp, dp + n + 1);

}