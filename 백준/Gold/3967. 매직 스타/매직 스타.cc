#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool isUsed[13];
int star[6][4] = { { 0, 2, 5, 7 }, { 0, 3, 6 ,10 }, { 1, 2, 3, 4 }, { 7, 8, 9, 10 }, {1, 5, 8, 11}, {4, 6, 9, 11} };
char input[12];
char board[5][9];
vector<string> ans;
bool check() {
	for (int i = 0; i < 6; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int idx = star[i][j];
			int num = input[idx] - 'A' + 1;
			sum += num;
		}
		if (sum != 26) return false;
	}
	return true;
}

void dfs(int idx) {
	if (idx == 12) {
		// 매직 스타 되는지 확인
		if (check()) {
			// 출력
			int k = 0;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 9; j++) {
					if (board[i][j] == '.') cout << '.';
					else cout << input[k++];
				}
				cout << endl;
			}
			exit(0);
		}
		return;
	}

	if (input[idx] == 'x') {
		// 채워야 함
		for (int i = 1; i <= 12; i++) {
			if (isUsed[i]) continue;
			input[idx] = i + 'A' - 1;
			isUsed[i] = 1;
			
			bool flag = 0; // 채운 줄이 26이 넘는지 확인
			for (int j = 0; j < 6; j++) {

				int sum = 0; // 합 
				int cnt = 0; // 채워진 갯수
				for (int k = 0; k < 4; k++) {
					int pos = star[j][k];
					if (input[pos] == 'x') continue; // 아직 비어있음
					sum += input[pos] - 'A' + 1; // 합 더함
					cnt++;
				}
				if (cnt == 4 && sum != 26) {
					// 4개가 전부 찼는데 26이 아닌 경우 제외
					flag = 1;
					break;
				}
				if (sum > 26) {
					// 26이 넘은 경우 제외
					flag = 1; 
					break;
				}
			}
			if(!flag) dfs(idx + 1);
			// 원복

			isUsed[i] = 0;
			input[idx] = 'x';
		}
	}
	else {
		// 안 채워도 됨
		dfs(idx + 1);
	}
}
int main() {

	string str;
	int k = 0;
	for (int i = 0; i < 5; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 9; j++) {
			board[i][j] = s[j]; // 출력 판
			if (s[j] == '.') continue;
			input[k++] = s[j];
			int num = s[j] - 'A' + 1;
			isUsed[num] = 1;
		}
	}
	dfs(0);
	
}