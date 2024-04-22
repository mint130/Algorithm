#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int n; 
int arr[12];
int op[4];
int max_answer = INT_MIN;
int min_answer = INT_MAX;
void dfs(int k, int ans) {
	if (k == n - 1) {
		//n-1번째 수까지 전부 사용하면 끝
		max_answer = max(max_answer, ans);
		min_answer = min(min_answer, ans);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			if (i == 0) {
				dfs(k + 1, ans + arr[k + 1]);
			}
			else if (i == 1) {
				dfs(k + 1, ans - arr[k + 1]);
			}
			else if (i == 2) {
				dfs(k + 1, ans * arr[k + 1]);
			}
			else {
				dfs(k + 1, ans / arr[k + 1]);
			}
			op[i]++;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	dfs(0, arr[0]);
	cout << max_answer << "\n";
	cout << min_answer << "\n";
}