#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

int arr[10];
int ans[10];
int isused[10];
vector<int> v;

void func(int k) {
	
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	int tmp = 0; //k번째 항을 채울 때마다 초기화
	for (int i = 0; i < n; i++) {
		//이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
		//arr의 i번째 값이 tmp와 같지 않을 때
		if (!isused[i] && arr[i] != tmp) {
			ans[k] = arr[i];
			tmp = ans[k]; //tmp는 이전에 선택한 값=이전 수열의 마지막 값
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;

		}

		//중복되는 수열을 여러번 출력하면 안 됨
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
	
	
	
	func(0);
	//k개가 채워진 수열
}