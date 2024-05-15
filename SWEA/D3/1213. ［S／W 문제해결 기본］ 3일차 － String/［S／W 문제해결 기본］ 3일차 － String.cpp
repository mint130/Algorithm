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
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 10;
	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;
		int answer = 0;
		string f;
		cin >> f;
		string str;
		cin >> str;
		while (1) {
			//cout << str << endl;
			if (str.find(f) == string::npos) {
				break;
			}
			int idx = str.find(f);
			int last = idx + f.length();
			str = str.substr(last);
			answer++;
		}
	
		cout << "#" << tc << " " << answer << "\n";
	
	}
}