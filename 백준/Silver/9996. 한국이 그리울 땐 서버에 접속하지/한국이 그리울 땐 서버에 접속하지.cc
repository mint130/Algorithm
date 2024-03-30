#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <math.h>
#include <string.h>
#include <tuple>
#include <queue>
using namespace std;
int n;
int main() {
	cin >> n;
	string pattern;
	cin >> pattern; //알파벳 소문자와 별표 한개

	int pos = pattern.find('*');
	//pos는 *의 위치, *를 기준으로 앞뒤로 분리
	string pat1 = pattern.substr(0, pos);
	string pat2 = pattern.substr(pos + 1, pattern.size() - pos - 1);

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		bool check = 0;
		if (pattern.size() - 1 > str.size()) {
			cout << "NE" << "\n";
			continue;
		}
		for (int i = 0; i < pat1.size(); i++) {
			if (str[i] != pat1[i]) {
				check = 1;
				break;
			}
		}
		for (int i = 0; i < pat2.size(); i++) {
			if (str[str.size() - pat2.size() + i] != pat2[i]) {
				check = 1;
				break;
			}
		}
		if (check) {
			cout << "NE" << "\n";
		}
		else {
			cout << "DA" << "\n";
		}
	}
}