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


int board[101][101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int tc = 1; tc <= 10; tc++) {
		int n;
		cin >> n;
		int ans = 0;
		memset(board, 0, sizeof(board));
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> board[i][j];
			}
		}
		int a = 0; //행 최대값
		for (int i = 0; i < 100; i++) {
			//i번째 행의 합 sum
			int sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += board[i][j];
			}
			a = max(sum, a);
		}
		int b = 0; //열 최대값
		for (int i = 0; i < 100; i++) {
			//i번째 열의 합 sum
			int sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += board[j][i];
			}
			b = max(sum, b);
		}
		int c = 0; //오른쪽 대각선 합
		//0 0, 1 1, 2 2, 3 3, 
		for (int i = 0; i < 100; i++) {
			c += board[i][i];
		}
		int d = 0; //왼쪽 대각선 최대값
		//0 99, 1 98, .. 99 0
		for (int i = 0; i < 100; i++) {
			d += board[i][99 - i];
		}
		ans = max({ a, b, c, d });
		cout << "#" << tc << " " << ans << "\n";
		
	}

}