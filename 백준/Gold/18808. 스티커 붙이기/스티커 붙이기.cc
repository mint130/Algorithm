#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, k; 
int row, col; //스티커의 세로, 가로
int board[42][42]; //노트북 
int sticker[42][42]; //스티커
int tmp[42][42];

bool possible(int x, int y) {
	//스티커를 노트북에 붙일 수 있는지
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (sticker[i][j] == 1 && board[x + i][y + j] == 1) return false;
		}
	}
	return true;
}
void rotate() {
	//스티커를 회전하는 함수
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			tmp[j][row - 1 - i] = sticker[i][j];
		}
	}
	swap(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			sticker[i][j] = tmp[i][j];
		}
	}

}
void stick(int x, int y) {
	//x, y는 스티커의 시작 지점
	//노트북에 스티커를 붙임=board의 값을 1로 바꿔줌
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (sticker[i][j] == 1) board[x + i][y + j] = 1;
		}
	}
}
void func() {
	for (int dir = 0; dir < 4; dir++) {
		//dir이 0 
		//dir이 1 90
		//dir이 2 180
		//dir이 3 270
		for (int i = 0; i + row <= n; i++) {
			for (int j = 0; j + col <= m; j++) {
				//스티커의 시작위치 정함
				//가장 왼쪽 위부터, 스티커가 노트북의 크기를 넘진 않아야하므로
				//i+row<=n, j+col<=m
				if (possible(i, j)) {
					stick(i, j);
					return;
				}
			}
		}
		//한 방향에 대한 검사가 끝나면 회전
		rotate();
	}
}
int main() {

	cin >> n >> m >> k;
	while (k--) {
		cin >> row >> col;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> sticker[i][j];
				//스티커 입력 받음
			}
		}
		func();
		//스티커를 노트북에 붙일 수 있는지
		memset(sticker, 0, sizeof(sticker));
		memset(tmp, 0, sizeof(tmp)); //0으로 초기화, memeset 가능
		//스티커 초기화

	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) ans++;
		}
	}
	cout << ans;
}