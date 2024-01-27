#include <iostream>
using namespace std;
int n, m;

int arr[10];

void func(int k) {
	//num은 수열에 마지막으로 들어간 수
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[k] = i;
		func(k + 1);		
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
	//k개가 채워진 수열
}