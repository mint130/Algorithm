#include <iostream>
#include <algorithm>
using namespace std;
int n, m;

int arr[10];
int ans[10];
int isused[10]; //arr의 idx번째 수가 사용 되었는지
void func(int k, int idx) {
	//arr[idx]가 마지막으로 들어간 수
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++) {
		//처음 입력받은 배열 arr에서 i번째 수가 쓰이지 않았다면
		if (!isused[i]) {
			ans[k] = arr[i];
			isused[i] = 1;
			func(k + 1, i);
			isused[i] = 0;
		}
	}

	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0,  0);
	//k개가 채워진 수열
}