#include <iostream>
#include <algorithm>
using namespace std;
int n;
int d[1002]; //2xn을 채울수있는 경우의 수
int main() {
	cin >> n;
	d[0] = 0;
	d[1] = 1;
	d[2] = 2; //가로 두개 세로 두개
	//d[3]은 
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}
	cout << d[n];
}