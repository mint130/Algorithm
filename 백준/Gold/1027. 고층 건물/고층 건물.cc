#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
double height[51];
int ans;
int cnt;

int main() {
	// 기울기 구하기
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		double tmp = 10000000000;
		for (int j = i-1; j >= 0; j--) {
			// 기울기가 작아져야 보임
			double d = (height[i] - height[j]) / ((double)i - (double)j);
			if (d < tmp) {
				tmp = d;
				cnt++;
			}
		}
		tmp = -1000000000;
		for (int j = i + 1; j < n; j++) {
			//기울기가 커지면 
			double d = (height[j] - height[i]) / ((double)j - (double)i);
			if (d > tmp) {
				tmp = d;
				cnt++;
			}
		}
		
		ans = max(cnt, ans);
	}
	cout << ans;
}