#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int n;
vector<long long> v;
void dfs(int idx, string s) {
	if (!s.empty() && s>="0" && s <= "9876543210") v.push_back(stoll(s));
	if (s == "9876543210") return;
	for (int i=0;i<=9;i++) {
		if (idx > 0) {
			if (i < s[idx - 1] - '0') {
				// 감소하는 수
				dfs(idx + 1, s + to_string(i));
			}
		}
		else {
			dfs(idx + 1, s + to_string(i));
		}
	}
}
int main() {
	cin >> n;
	dfs(0, "");
	sort(v.begin(), v.end());
	// size: 1023 -> 1024부터 -1 출력
	if (n > v.size()) cout << -1;
	else cout << v[n - 1];
}