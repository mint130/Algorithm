#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
using namespace std;
int h[21]; //점원 키
int n;
int b;
int ans;
void dfs(int cnt, int height) {
	
	if (cnt == n+1) {
		if (height >= b) {
			ans = min(ans, height);
		}
		return;
	}
	dfs(cnt + 1, height + h[cnt]);
	dfs(cnt + 1, height);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> b;
		//점원 n명
		//선반 높이 b
		fill(h, h + 21, 0);
		ans = 987654321;
		for (int i = 1; i <= n; i++) {
			cin >> h[i];
		}
		int st, en = 0;
		dfs(0, 0);
		cout << "#" << tc << " " << ans-b << "\n";
	}
}