#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int a[1000002];
int b[1000002];
int main() {
	int n, m;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int idx_a = 0;
	int idx_b = 0; //a와 b의 인덱스
	while (idx_a < n && idx_b < m) {
		if (a[idx_a] < b[idx_b]) {
			//v.push_back(a[idx_a]);
			cout << a[idx_a] << " ";
			idx_a++;
		}
		else {
			//v.push_back(b[idx_b]);
			cout << b[idx_b] << " ";
			idx_b++;
		}
	}
	while (idx_a < n) {
		cout << a[idx_a] << " ";
		idx_a++;
	}
	while (idx_b < m) {
		cout << b[idx_b] << " ";
		idx_b++;
	}

	
}