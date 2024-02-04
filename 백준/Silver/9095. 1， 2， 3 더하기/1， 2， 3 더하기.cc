#include <iostream>

using namespace std;

int d[12]; //n를 1,2,3의 합으로 나타내는 방법의 수
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		d[1] = 1;
		d[2] = 2; //2, 1+1
		d[3] = 4; //3. 1+2, 2+1, 1+1+1
		
		for (int i = 4; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		//cout << ans;
		cout << d[n] << "\n";
	}
}