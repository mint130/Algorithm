#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
int n, m;
int arr[500002];
//target이 들어갈 수 있는 가장 왼쪽 위치

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		//cout << upper_idx(num, n) - lower_idx(num, n) << " ";
		cout << upper_bound(arr, arr + n, num) - lower_bound(arr, arr + n, num) << " ";
	}
	
}