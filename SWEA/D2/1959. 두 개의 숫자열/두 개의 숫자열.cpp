#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string.h>
#include <cstring>

using namespace std;


int a[32];
int b[32];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int answer = 0;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		int len = max(n, m) - min(n, m);
		for (int i = 0; i <= len; i++) {
			int sum = 0;
			for (int j = 0; j < min(n, m); j++) {
				if (n > m) {
					sum += a[j + i] * b[j];
				}
				else {
					sum += a[j] * b[j + i];
				}
			}
			answer = max(answer, sum);
		}

		cout << "#" << tc << " " << answer << "\n";
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}

}