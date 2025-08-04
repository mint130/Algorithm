#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[9];
bool visited[9];
vector<int> v;
int ans = -999;
void dfs(int cnt) {
	if (cnt == n) {
		int sum = 0;
		for (int i = 0; i < n-1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		v.push_back(arr[i]);
		dfs(cnt + 1);
		visited[i] = 0;
		v.pop_back();

	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(0);
	cout << ans;

}