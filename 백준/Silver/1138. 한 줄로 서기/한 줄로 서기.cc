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
int arr[11];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int left;
		cin >> left;
		//i앞에 더 큰 수가 몇개 있는지
		//i가 들어갈 자리 앞에 빈자리가 left개 있어야 함
		int blank = 0; //빈자리 갯수
		for (int j = 0; j < n; j++) {
			if (blank == left && !arr[j]) {
				arr[j] = i + 1;
				break;
			}
			if (!arr[j]) blank++;

		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}