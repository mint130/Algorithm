#include <iostream>
using namespace std;
int n;
int cnt = 0;
int column[16]; //column[i] = k i번째 행은 k열에 퀸이 있음
bool promising(int cur) {
	
	for (int i = 0; i < cur; i++) {
		//0부터 cur-1행 까지 탐색하며 같은 열이나 대각선상에 퀸이 있는지 확인, 있으면 false
		if (column[i] == column[cur] || cur - i == abs(column[cur] - column[i])) {
			return false;
		}
	}
	return true;
}
void func(int cur) {
	//cur번째 행에 말을 배치
	if (cur == n) 
	{ 
		cnt++; 
		return; 
	}

	for (int i = 0; i < n; i++) {
		//cur번째 행 i번째 열에 퀸을 둬 봄
		column[cur] = i;

		if (promising(cur)) {
			//유망하다면 다음 행에 놓아봄
			func(cur + 1);

		}
	}

}
int main() {
	cin >> n;
	//어차피 한 행에 하나의 퀸만 존재하기 때문에, 열의 위치만 받아도 됨
	func(0);
	cout << cnt;
}