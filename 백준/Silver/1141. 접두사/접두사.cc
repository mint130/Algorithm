#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<string> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	vector<bool> check(n, true);
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[j].find(v[i]) == 0) {
				check[i] = false;
				break;
			}
		}
	}
	int ans = 0;
	for (auto i : check) {
		if (i) ans++;
	}
	cout << ans;
}
