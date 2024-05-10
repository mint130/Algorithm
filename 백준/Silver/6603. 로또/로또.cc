#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int s[14];
bool isused[14];
int arr[7]; //채워지는 배열
int k;
void dfs(int idx, int cnt) {
	//s에서 idx번째 숫자를 고름, 6개 중 cnt까지 채움
	//s의 인덱스 idx, arr의 인덱스 cnt
	if (cnt == 6) {
		//6번째 숫자까지 다 골랐다면
		for (int i = 0; i < 6; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i < k; i++) {
		//arr[cnt]에 s 집합의 i번째 숫자가 들어감
		
		arr[cnt] = s[i];
		dfs(i + 1, cnt + 1);

	}
	
	


}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//1~49에서 k개의 수를 골라 집합을 만들고 그 수만 가지고 번호 선택
	//집합 s와 k가 주어짐
	
	while (1) {
		cin >> k;
		memset(s, 0, sizeof(s));
		if (k == 0) {
			return 0;
		}
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}
		dfs(0, 0);
		cout << "\n";
	}
}