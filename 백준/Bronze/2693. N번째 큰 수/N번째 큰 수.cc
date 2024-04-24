#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string.h>
#include <cstring>

using namespace std;
vector<int> v(10);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 10; j++) {
			int num;
			cin >> num;
			v[j] = num;
		}
		sort(v.begin(), v.end());
		cout << v[7] << "\n";
		
	}
}