#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int arr[100002];
int binarysearch(int target, int start, int finish) {
	if (start > finish) return 0;
	int mid = (start + finish) / 2;
	if (arr[mid] == target) return 1;
	if (arr[mid] < target) {
		return binarysearch(target, mid + 1, finish);
	}
	else {
		return binarysearch(target, start, mid - 1);
	}
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
		cout << binarysearch(num, 0, n-1) << "\n";
	}
}