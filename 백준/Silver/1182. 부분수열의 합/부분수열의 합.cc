#include <iostream>

using namespace std;
int n, s;
int cnt = 0; //부분 수열 s가 되는 경우의 수
int arr[22]; 
int flag = 0; //s가 0인 경우 때문에
void func(int cur, int sum) {
	//cur: 부분 수열의 원소 갯수
	//sum: 지금까지 수열의 합

	if (cur == n) {
		//각 수가 들어가는 지 안 들어가는 지 모든 경우의 수를 구해야 함
		if (sum == s) {
			cnt++;
		}
		return;
	}

	//현재 수 포함 x
	func(cur + 1, sum);
	//현재 수 포함
	func(cur + 1, sum + arr[cur]);

}

int main() {

	cin >> n >> s;
	//정수의 갯수 n, 만들고 싶은 부분 수열 s
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	func(0, 0);
	if (s == 0) cnt--; //s가 0일 때 공집합
	cout << cnt;
}