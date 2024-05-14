#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <set>
#include <queue>
using namespace std;
int answer;
int board[5][5];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
set<string> s;
void dfs(int x, int y, string str, int cnt) {
	//str은 현재 만들어진 수 문자열
	if (cnt == 7) {
		//cout << str << endl;
		s.insert(str);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
		int num = board[nx][ny];
		string nxt = str + to_string(num);
		dfs(nx, ny, nxt, cnt + 1);
		
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		answer = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> board[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dfs(i, j, to_string(board[i][j]), 1);
			}
		}
		answer = s.size();
		cout << "#" << tc << " " << answer << '\n';
		s.clear();
	}
}