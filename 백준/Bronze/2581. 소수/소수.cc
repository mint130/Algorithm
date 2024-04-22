#include <iostream>
#include <vector>
using namespace std;
int arr[10002];
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n;
	cin >> m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		arr[i] = 1;
	}
	arr[1] = 0;
	//arr[i]가 1이면 소수
	for (int i = 2; i * i <= n; i++) {
		if (!arr[i]) continue;
		for (int j = 2 * i; j <= n; j += i) {
			arr[j] = 0;
		}
	}
	int sum = 0;
	for (int i = m; i <= n; i++) {
		if (arr[i]) {
			sum += i;
			v.push_back(i);
		}	
	}
	if (v.empty()) { cout << -1; return 0; }
	cout << sum << "\n";
	cout << v[0];
		
}