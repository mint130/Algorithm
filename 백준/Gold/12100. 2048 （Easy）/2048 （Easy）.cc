#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int ans;
int n;

int board[22][22];

void up() {
	queue<int> tmp;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (board[i][j]) tmp.push(board[i][j]);
			board[i][j] = 0;
		}
		for (int i = 0; i < n; i++) {
			if (!tmp.empty()) {
				int num = tmp.front();
				tmp.pop();
				if (!tmp.empty() && tmp.front() == num) {
					board[i][j] = 2 * num;
					tmp.pop();
				}
				else {
					board[i][j] = num;
				}
			}
		}
	}
}
void right() {
	queue<int> tmp;
	//가장 오른쪽으로
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (board[i][j] != 0) tmp.push(board[i][j]);
			board[i][j] = 0;
		}
		for (int j = n - 1; j >= 0; j--) {
			if (!tmp.empty()) {
				int num = tmp.front();
				tmp.pop();
				//바로 뒤에 있는 수가 현재와 동일한지 확인
				if (!tmp.empty() && tmp.front() == num) {
					board[i][j] = 2 * num;
					tmp.pop();
				}
				else {
					board[i][j] = num;
				}
			}
		}
	}
}
void left() {
	
	queue<int> tmp;
	//가장 왼쪽으로 배열을 옮김
	//같은 숫자들끼리 체크하여 합침
	//다시 가장 왼쪽으로 배열을 옮김
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//가장 왼쪽으로 옮김
			if (board[i][j] != 0) tmp.push(board[i][j]);
			board[i][j] = 0;
		}
		for (int j = 0; j < n; j++) {
			if (!tmp.empty()) {
				int num = tmp.front();
				tmp.pop();
				//바로 뒤에 있는 수가 현재와 동일한지 확인
				if (!tmp.empty() && tmp.front()==num) {
					board[i][j] = 2 * num;
					tmp.pop();
				}
				else {
					board[i][j] = num;
				}
			}
		}

	}
}

void down() {
	queue<int> tmp;
	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (board[i][j]) tmp.push(board[i][j]);
			board[i][j] = 0;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (!tmp.empty()) {
				int num = tmp.front();
				tmp.pop();
				if (!tmp.empty() && tmp.front() == num) {
					board[i][j] = 2 * num;
					tmp.pop();
				}
				else {
					board[i][j] = num;
				}
			}
		}
	}
}
void func(int k) {
	if (k == 5) {
		//k는 이동 횟수
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans = max(ans, board[i][j]);
			}
		}
		return;
	}
	int tmp[22][22];
	for (int dir = 0; dir < 4; dir++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp[i][j] = board[i][j];
			}
		}
		//배열을 옮겨놓음

		if (dir == 0) {
			up();
		}
		else if (dir == 1) {
			right();
		}
		else if (dir == 2) {
			left();
		}
		else {
			down();
		}

		func(k + 1);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = tmp[i][j];
			}
		}

	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	func(0);
	cout << ans;

}