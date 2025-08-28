#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, a, b;
long long arr[100002];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int st = 0;
	int en = n - 1;
	long long ans = 9876543210;
	
	while (st < en && st>=0 && en<n) {
		long long sum = arr[st] + arr[en];
		if (abs(sum) < ans) {
			a = arr[st];
			b = arr[en];
			ans = abs(sum);
		}
		if (sum > 0) {
			// 0에 가까워지기 위해 
			en--;
		}
		else if(sum < 0) {
			st++;
		}
		else {
			cout << arr[st] << " " << arr[en];
			return 0;
		}
	}
	cout << a << " " << b;
}