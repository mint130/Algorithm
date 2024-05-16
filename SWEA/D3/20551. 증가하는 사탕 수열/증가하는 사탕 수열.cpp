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
int arr[3];
int answer;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		answer = 0;
		cin >> arr[0] >> arr[1] >> arr[2];
		if (arr[1] >= arr[2]) {
			while (arr[1] >= arr[2]) {
				arr[1]--;
				answer++;
				if (arr[1] <= 0) {
					answer = -1;
					break;
				}
			}
		}
		if (answer != -1) {
			if (arr[0] >= arr[1]) {
				while (arr[0] >= arr[1]) {
					arr[0]--;
					answer++;
					if (arr[0] <= 0) {
						answer = -1;
						break;
					}
				}
			}
		}
		cout << "#" << tc << " " << answer << "\n";

	}
	
}