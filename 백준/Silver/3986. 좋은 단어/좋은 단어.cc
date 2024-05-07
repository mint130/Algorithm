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
	int answer = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		stack<char> st;

		for (int j = 0; j < s.length(); j++) {
			if (!st.empty()) {
				char c = st.top();
				if (c != s[j]) {
					st.push(s[j]);
				}
				else {
					st.pop();
				}
			}
			else {
				st.push(s[j]);
			}
		}
		if (st.empty()) answer++;
		
		
	}
	cout << answer << "\n";
}