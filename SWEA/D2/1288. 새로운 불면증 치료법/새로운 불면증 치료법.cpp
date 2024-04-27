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
int arr[10];
bool check() {
	for (int i = 0; i < 10; i++) {
		if (!arr[i]) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int answer = 0;
		int n;
		cin >> n;
		int i = 1;
		int ans = 0;
		while (1) {
			if (check()) {
				//0부터 9까지 모두 셌음
				answer = ans;
				break;
			}
			ans = n * i;
			string str = to_string(ans);
			for (int j = 0; j < str.length(); j++) {
				if (!arr[str[j]-'0']) arr[str[j]-'0'] = 1;
			}
			i++;
		}
		cout << "#" << tc << " " << answer << "\n";
		fill(arr, arr + 10, 0);

	}
	
}