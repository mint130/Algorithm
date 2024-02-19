#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

int arr[100000];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int st = 0;
	int en = 0;
	int ans = 2000000001;
	while (st < n && en < n) {
		if (arr[en] - arr[st] >= m) {
			ans = min(ans, arr[en] - arr[st]);
			st++;
		}
		else {
			en++;
		}
	}
	cout << ans;
}