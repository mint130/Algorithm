#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int n;

int main() {
	cin >> n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	map <string, int, greater<string>> s;
	for (int i = 0; i < n; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		if (str2 == "enter") {
			s[str1] = 1;
		}
		else {
			s.erase(str1);
		}
	}

	for (auto it = s.begin(); it != s.end(); it++) {
		cout << it->first << "\n";
	}
	
}