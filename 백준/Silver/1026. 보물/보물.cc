#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[52];
int b[52];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	//a는 정방향, b는 역방향으로 곱함
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = ans + a[i] * b[n - 1 - i];
	}
	cout << ans;
}