#include <iostream>

using namespace std;

int d[302][3]; //j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을 때 점수 합의 최댓값
int score[302]; //n번째 계단의 점수

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> score[i];
	}
	if (n == 1) {
		cout << score[1];
		return 0;
	}
	d[1][1] = score[1];
	d[1][2] = 0;
	d[2][1] = score[2];
	d[2][2] = score[1] + score[2];
	for (int i = 3; i <= n; i++) {
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + score[i];
		d[i][2] = d[i - 1][1] + score[i];
	}
	cout << max(d[n][1], d[n][2]);

}