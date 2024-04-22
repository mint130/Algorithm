#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[10];
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	int a, b = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				a = i;
				b = j;
				break;
			}
		}
	}
	
	for (int i = 0; i < 9; i++) {
		if (i == a || i == b) continue;
		v.push_back(arr[i]);
	}
	sort(v.begin(), v.end());
	for (auto i : v) {
		cout << i << "\n";
	}
	
}