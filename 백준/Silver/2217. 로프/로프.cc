#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[100002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] * (n - i) > ans) {
			ans = arr[i] * (n - i);
		}
	}
	cout << ans;
}