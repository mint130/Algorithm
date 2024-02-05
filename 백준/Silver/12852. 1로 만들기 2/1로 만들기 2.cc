#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int d[1000002];
int pre[1000002]; //경로 복원용(지나왔던 idx 저장)
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> v;
	d[1] = 0;
	pre[1] = 0;
	
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 2 == 0 && d[i / 2] + 1 < d[i]) {
			d[i] = d[i / 2] + 1;
			pre[i] = i / 2;
		}
		if (i % 3 == 0 && d[i / 3] + 1 < d[i]) {
			d[i] = d[i / 3] + 1;
			pre[i] = i / 3;
		}
	}
	cout << d[n] << '\n';
	int ans = n;
	while (1) {
		cout << ans << " ";
		if (ans == 1) break;
		ans = pre[ans];
	}

}