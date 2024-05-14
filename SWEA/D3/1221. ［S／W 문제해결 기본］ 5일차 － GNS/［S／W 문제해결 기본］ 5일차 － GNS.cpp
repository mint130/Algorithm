#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
using namespace std;
map<string, int> m1;
map<int, string> m2;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	m1["ZRO"] = 0; m2[0] = "ZRO";
	m1["ONE"] = 1; m2[1] = "ONE";
	m1["TWO"] = 2; m2[2] = "TWO";
	m1["THR"] = 3; m2[3] = "THR";
	m1["FOR"] = 4; m2[4] = "FOR";
	m1["FIV"] = 5; m2[5] = "FIV";
	m1["SIX"] = 6; m2[6] = "SIX";
	m1["SVN"] = 7; m2[7] = "SVN";
	m1["EGT"] = 8; m2[8] = "EGT";
	m1["NIN"] = 9; m2[9] = "NIN";

	for (int tc = 1; tc <= T; tc++) {
		string str;
		int n;
		cin >> str >> n;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(m1[s]);
		}
		sort(v.begin(), v.end());
		cout << "#"<<tc << "\n";
		for (auto i : v) {
			cout << m2[i] << " ";
		}
		cout << "\n";
	}
	
}