#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t;
vector<int> v1;
vector<int> v2;
int gcd(int a, int b) {
	//최대 공약수
	if (a == 0) return b;
	return gcd(b % a, a);
}
int lcm(int a, int b) {
	//최소 공배수
	return a / gcd(a, b) * b;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		//x y가 k번째 해
		//m n이 마지막 해
		//x<m이면 x=x+1 y<n이면 y=y+1
		int last = 0;
		if (n < m) last = lcm(n, m);
		else last = lcm(m, n);
		//월 구하기
		for (int k = 0; m * k + x <= last; k++) {
			v1.push_back(m * k + x);
		}
		
		for (int k = 0; n * k + y <= last; k++) {
			v2.push_back(n * k + y);
		}
		int idx_m = 0;
		int idx_n = 0;
		bool flag = 0;
		while (idx_m < v1.size() && idx_n < v2.size()) {
			if (v1[idx_m] < v2[idx_n]) idx_m++;
			else if (v1[idx_m] == v2[idx_n]) {
				cout << v1[idx_m] << "\n";
				flag = 1;
				break;
			}
			else idx_n++;
		}
		if (flag == 0) cout << -1 << "\n";
		v1.clear();
		v2.clear();

	}
}