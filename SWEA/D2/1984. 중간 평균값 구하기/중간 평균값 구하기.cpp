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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int answer = 0;
		vector<int> v;
		for (int i = 0; i < 10; i++) {
			int n;
			cin >> n;
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		float sum = 0;
        int isum=0;
		for (int i = 1; i <= 8; i++) {
			sum += v[i];
            isum+=v[i];
		}
		sum = sum / 8;
		if (sum - (int)sum >= 0.5) {
			
			answer = (int)sum + 1;
		}
		else answer = (int)sum;
		cout << "#" << tc << " " << answer << "\n";
	}
}