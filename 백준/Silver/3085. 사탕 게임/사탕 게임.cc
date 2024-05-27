#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
char board[51][51];
int n;

int maxcnt = 0; //가장 길게 연속
void check() {
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (board[i][j] == board[i][j + 1]) {
				cnt++;
			}
			else {
				//다른 색 발견
				if (cnt > maxcnt) {
					maxcnt = cnt;
				}
				cnt = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (board[j][i] == board[j + 1][i]) {
				cnt++;
			}
			else {
				if (cnt > maxcnt) {
					maxcnt = cnt;
				}
				cnt = 1;
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//사탕의 색이 다른 인접한 두칸 고름
	//사탕 교환
	//같은 색으로 이루어져 있는 가장 긴 연속 부분 행/열 고르고 사탕을 먹는다
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			//가로
			swap(board[i][j], board[i][j + 1]);
			//최대 갯수 구함
			check();
			//다시 원래대로
			swap(board[i][j], board[i][j + 1]);
			
			//세로
			swap(board[j][i], board[j + 1][i]);
			check();
			swap(board[j][i], board[j + 1][i]);
			
		}
	}
	
	cout << maxcnt;
}