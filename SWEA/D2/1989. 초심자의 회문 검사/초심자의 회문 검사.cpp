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
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		
		string s;
		cin >> s;
		bool flag = 1;

		int st = 0;
		int en = s.length() - 1;
		while (st <= en) {
			if (s[st] != s[en]) {
				flag = 0;
				break;
			}
			st++;
			en--;
		}
		
		cout << "#" << tc << " " << flag << "\n";
	}
}