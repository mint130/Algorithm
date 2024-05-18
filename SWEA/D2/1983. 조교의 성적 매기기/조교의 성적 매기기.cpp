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
string grade[10] = { "A+", "A0", "A-","B+", "B0", "B-", "C+", "C0", "C-", "D0" };
bool cmp(pair<float, int> p1, pair<float, int> p2) {
	if (p1.first != p2.first) return p1.first > p2.first;
	else return p1.second > p2.second;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n, k;
		cin >> n >> k;
		int cnt = n / 10;
		string answer = "";
		vector<pair<float, int>> v;
		for (int i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			float score = a * 0.35 + b * 0.45 + c * 0.2;
			v.push_back({ score, i + 1 });
		}
		sort(v.begin(), v.end(), cmp);

		int idx = 0;
		for (int i = 0; i < v.size(); i = i + cnt) {
			for (int j = 0; j < cnt; j++) {
				string s = grade[idx];
				if (v[j + i].second == k) {
					answer = s;
				}
			}
			idx++;

		}
		cout << "#" << tc << " " << answer << "\n";
	}
}