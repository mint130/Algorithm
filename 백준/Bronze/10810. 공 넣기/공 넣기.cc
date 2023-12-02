#include <iostream>
#include <string>
int num[101]={0,};
using namespace std;
int main() {
	//fill(num, num + 101, 0);
	int m, n;
	cin >> n >> m;
	for (int t = 0; t < m; t++) {
		int i, j, k;
		cin >> i >> j >> k;
		//i번 바구니부터 j번 바구니까지 k번 번호가 적혀져있는 공을 넣는다
		for (int r = i; r <= j; r++) {
			num[r] = k;
		}
	}
	for (int i = 1; i <=n; i++) {
		cout << num[i] << " ";
	}
}