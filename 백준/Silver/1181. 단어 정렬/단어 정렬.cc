#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
bool cmp(string a, string b) {
	if (a.length() != b.length()) return a.length() < b.length();
	else {
		return a < b;
	}
}
vector <string> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}