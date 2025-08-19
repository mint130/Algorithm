#include <iostream>
using namespace std;
int arr[14];
int num;
int ans[6];
void dfs(int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	// 0부터 num까지 중 6개 뽑는 조합 
	for (int i = idx; i < num; i++) {
		ans[cnt] = arr[i];
		dfs(i + 1, cnt + 1);
		ans[cnt] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		cin >> num;
		if (num == 0) {
			return 0;
		}
		else {
			for (int i = 0; i < num; i++) {
				cin >> arr[i];
			}
			dfs(0, 0);
			cout << "\n";
		}
	}
}