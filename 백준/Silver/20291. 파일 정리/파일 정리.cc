#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
using namespace std;
map<string, int> m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int j = 0;
		for (j = 0; j < str.length(); j++) {
			if (str[j] == '.') break;
		}
		string str2 = str.substr(j + 1);
		m[str2]++;
	}
	for (auto i : m) {
		cout << i.first << " " << i.second << "\n";
	}
}