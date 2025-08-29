#include <iostream>
#include <algorithm>
using namespace std;
int n, ans;
long long arr[2001];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		long long target = arr[i];
		int st = 0;
		int en = n - 1;
		while (st < en) {
			if (arr[st] + arr[en] == target) {
				if (st != i && en != i) {
					ans++;
					break;
				}
				else if (st == i) st++;
				else if (en == i) en--;
			}
			else if (arr[st] + arr[en] < target) {
				st++;
			}
			else {
				en--;
			}
			
		}
	}
	cout << ans;
}