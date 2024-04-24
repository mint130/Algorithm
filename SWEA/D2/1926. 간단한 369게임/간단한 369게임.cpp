#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string.h>
#include <cstring>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		int cnt = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '3' || s[j] == '6' || s[j] == '9') {
				cnt++;
			}
		}
		if (!cnt) cout << i << " ";
		else {
			for (int j = 0; j < cnt; j++) {
				cout << "-";
			}
			cout << " ";
		}
	}
}