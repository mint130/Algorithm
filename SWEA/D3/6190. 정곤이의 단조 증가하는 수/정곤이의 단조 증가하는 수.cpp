#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;
int arr[1001];
int n;
int answer;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		answer = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int num = arr[i] * arr[j];
				string str = to_string(num);
				bool flag = 0;
				for (int k = 0; k < str.length() - 1; k++) {
					if (str[k] > str[k + 1]) { flag = 1; break; }
				}
				if (!flag) {
					answer = max(answer, num);
				}
				
			}
		}
       	if(answer==0) answer=-1;
		cout << "#" << tc << " " << answer << "\n";
	}
}