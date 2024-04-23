#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		long long ans = 0;
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		long long max = v[v.size() - 1];
		for (int i = v.size() - 2; i >= 0; i--) {
			if (v[i] < max) {
				ans += max - v[i];
			}
			else max = v[i];
		}
		cout << "#" << tc << " " << ans << "\n";
	}
}