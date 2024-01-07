#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
vector<int> ans;
vector<int> v;
int main() {
	int n;
	cin >> n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;
\
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		v.push_back(m);
	}

	reverse(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		
		while (!s.empty()) {
			if (s.top() > v[i]) {
				ans.push_back(s.top());
				break;
			}
			s.pop();
		}

		if (s.empty()) {
			ans.push_back(-1);
		}
		s.push(v[i]);
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}