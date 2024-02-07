#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int arr[1002];
vector<int> two;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {	
		cin >> arr[i];
	}
	sort(arr, arr + n);
	//arr 배열의 두 수를 합친 수 two 배열을 채움
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			two.push_back(arr[i] + arr[j]);
		}
	}
	sort(two.begin(), two.end());
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			//a[l]-a[k]이 two 배열 안에 있는지 확인
			if (binary_search(two.begin(), two.end(), arr[i] - arr[j])) { 
				cout << arr[i]; 
				return 0;
			}
		}
	}

}