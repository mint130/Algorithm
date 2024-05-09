#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
using namespace std;
int arr[11]; //카약의 갯수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s, r;
	cin >> n >> s >> r;
	int answer = 0;
	fill(arr, arr+11, 1);
	for (int i = 0; i < s; i++) {
		int idx;
		cin >> idx;
		arr[idx] = 0;
	}
	for (int i = 0; i < r; i++) {
		int idx;
		cin >> idx;
		arr[idx]++;
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] > 1) {
			if (i>1 && !arr[i - 1]) {
				arr[i - 1]++;
				arr[i]--;

			}
			else if (i<n && !arr[i + 1]) {
				arr[i + 1]++;
				arr[i]--;
			}
		}
		
	}
	for (int i = 1; i <= n; i++) {
		if (!arr[i]) answer++;
	}
	cout << answer;
}