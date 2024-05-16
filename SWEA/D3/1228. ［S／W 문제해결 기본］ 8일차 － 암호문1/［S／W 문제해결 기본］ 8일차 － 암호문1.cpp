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

int answer;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 10;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		int k; //명령어
		cin >> k;
		for (int i = 0; i < k; i++) {
			char c;
			int x, y;
			cin >> c >> x >> y;
			for (int j = 0; j < y; j++) {
				int num;
				cin >> num;
				v.insert(v.begin() + x + j, num);
			}
		}
		cout << "#" << tc << " ";
		for (int i = 0; i < 10; i++) cout << v[i] << " ";
		cout << "\n";
	}
	
}