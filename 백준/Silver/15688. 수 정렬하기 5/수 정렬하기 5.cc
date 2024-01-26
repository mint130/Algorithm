#include <iostream>
#include <algorithm>
using namespace std;
int n;
int freq1[1000002]; //양수 빈도 
int freq2[1000002]; //음수 빈도, 음수는 큰 것 부터
//counting sort
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int cnt1 = 0;
	int cnt2 = 0; //양수, 음수 횟수
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num >= 0) {
			cnt1++;
			freq1[num]++;
		}
		else {
			cnt2++;
			freq2[abs(num)]++;
		}

	}
	int i = 1000001;
	while (cnt2>0) {
		if (freq2[i] > 0) {
			for (int j = 0; j < freq2[i]; j++) {
				cout << -i << "\n";
				cnt2--;
			}
		}
		i--;
	}
	i = 0;
	//음수 먼저 출력
	while (cnt1>0) {
		if (freq1[i] > 0) {
			for (int j = 0; j < freq1[i]; j++) {
				cout << i << "\n";
				cnt1--;
			}
		}
		i++;
	}
}