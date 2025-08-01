#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int arr[10]; // 0이면 < 1이면 >
bool used[10];
int n;
string smax, smin;
void dfs(int idx, string s) {
	if (idx==n+1) {
		bool flag = 0;
		for (int i = 0; i < s.length()-1; i++) {
			int cur = s[i] - '0';
			int nxt = s[i + 1] - '0';
			if (arr[i] == 0) {
				// <
				if (cur >= nxt) flag = 1;
			}
			else {
				// >
				if (cur <= nxt) flag = 1;
			}
		}
		if (!flag) {
			smax = max(s, smax);
			smin = min(s, smin);
		}
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (used[i]) continue;
		used[i] = 1;
		dfs(idx + 1, s + to_string(i));
		used[i] = 0;

	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '<') arr[i] = 0;
		else arr[i] = 1;
	}
	smin = "999999999";
	dfs(0, "");
	cout << smax << "\n" << smin;
}