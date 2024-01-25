#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int ans[8];

void func(int x) {
	//x는 현재까지 골라진 수 갯수
	//같은 수를 여러번 골라도 됨
	if (x == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		
		ans[x] = arr[i];
		func(x + 1);
		
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//n개의 자연수 중에서 m개를 고름
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//arr 0부터 n-1까지 
	sort(arr, arr + n);

	func(0);
}