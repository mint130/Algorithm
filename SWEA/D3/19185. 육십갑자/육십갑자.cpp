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
string str1[22];
string str2[22];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n, m;
		cin >> n >> m;
		fill(str1, str1 + 22, "");
		fill(str2, str2 + 22, "");
		for (int i = 0; i < n; i++) {
			cin >> str1[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> str2[i];
		}
		int q;
		cin >> q;
		vector<string> answer;
		for (int i = 0; i < q; i++) {
			int num;
			cin >> num;
			int idx1 = (num - 1) % n;
			int idx2 = (num - 1) % m;
			string str = str1[idx1] + str2[idx2];
			answer.push_back(str);
		}
		cout << "#" << tc << " ";
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
	}
}