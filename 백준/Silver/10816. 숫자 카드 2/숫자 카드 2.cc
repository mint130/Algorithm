#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
int n, m;
int arr[500002];
//target이 들어갈 수 있는 가장 왼쪽 위치
int lower_idx(int target, int len) {
	int start = 0;
	int end = len;
	while (start != end) {
		int mid = (start + end) / 2;
		if (arr[mid] >= target) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}
	return start;
}
//target이 들어갈 수 있는 가장 오른쪽 위치
int upper_idx(int target, int len) {
	int start = 0;
	int end = len;
	while (start != end) {
		int mid = (start + end) / 2;
		if (arr[mid] > target) {
			//target이 내가 찾은 위치보다 작아야 함
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}
	return start;

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		cout << upper_idx(num, n) - lower_idx(num, n) << " ";
	}
	
}