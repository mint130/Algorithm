#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <queue>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 10;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;
		stack<char> st;
		bool answer = 1;
		string s;
		cin >> s;
		for (int i = 0; i < n; i++) {
			char c = s[i];
			if (c == '(' || c == '{' || c == '[' || c == '<') st.push(c);
			else if (c == ')') {
				if (st.top() == '(') st.pop();
				else {
					answer = 0;
					break;
				}
			}
			else if (c == '}') {
				if (st.top() == '{') st.pop();
				else {
					answer = 0;
					break;
				}
			}
			else if (c == ']') {
				if (st.top() == '[') st.pop();
				else {
					answer = 0;
					break;
				}
			}
			else if (c == '>') {
				if (st.top() == '<') st.pop();
				else {
					answer = 0;
					break;
				}
			}

		}
		if (!st.empty()) answer = 0;
		cout << "#" << tc << " " << answer << "\n";
	}
}