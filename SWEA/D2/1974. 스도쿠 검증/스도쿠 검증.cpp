#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string.h>
#include <cstring>

using namespace std;
int board[9][9];
int arr[10]; //1부터 9까지 들어있음

void init() {
	for (int i = 1; i <= 9; i++) {
		arr[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		int board[9][9];
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> board[i][j];
			}
		}
		bool flag = 1;

		//col
		for (int i = 0; i < 9; i++) {
			init();
			for (int j = 0; j < 9; j++) {
				int n = board[i][j];
				if (arr[n] > 0) {
					flag = 0;
					break;
				}
				else arr[n]++;
			}
		}
		//row
		for (int i = 0; i < 9; i++) {
			if (!flag) break;
			init();
			for (int j = 0; j < 9; j++) {
				int n = board[j][i];
				if (arr[n] > 0) {
					flag = 0;
					break;
				}
				else arr[n]++;
			}
		}
		//box
		for (int i = 0; i < 9; i = i + 3) {
			if (!flag) break;
			for (int j = 0; j < 9; j = j + 3) {
				init();
				for (int r = 0; r < 3; r++) {
					for (int c = 0; c < 3; c++) {
						int n = board[i + r][j + c];
						if (arr[n] > 0) {
							flag = 0;
							break;
						}
						else arr[n]++;
					}
				}
			}
		}



		cout << "#" << tc << " " << flag << "\n";
		memset(board, 0, sizeof(board));
		memset(arr, 0, sizeof(arr));
	}

}