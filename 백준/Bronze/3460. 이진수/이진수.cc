#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int n;
		cin >> n;
		vector<int> v;
		while (1) {
			if (n == 1) {
				v.push_back(n);
				break;
			}
			v.push_back(n % 2);
			n /= 2;
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 1) cout << i << " ";
		}
		cout << "\n";
	}
}