#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int i = 0;
	while (n > i) {
		n = n - i;
		i++;
	}
	//i번째 대각선에서 n번째 위치->i의 홀짝 따라 분모 분자 위치 바뀜
	//i가 홀수면 분자 증가 분모 감소: n이 분모
	//i가 짝수면 분자 감소 분모 증가: n이 분자
	if (i % 2 == 0) {
		//분자 감소 분모 증가
		cout << n << "/" << i + 1 - n;
	}
	else {
		//분자 증가 분모 감소
		cout << i + 1 - n << "/" << n;
	}

}