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
int board[12][12]; //i번 선수가 j번째 포지션에 있을 때 능력치
bool visit[12]; //i번째 포지션은 k번째 선수 position[i]=k
int answer; //능력치의 합

void dfs(int k, int sum) {
	if (k == 11) {
		//모든 사람의 포지션 다 정함
		answer = max(sum, answer);
		return;
	}
	for (int i = 0; i < 11; i++) {
		//k번째 사람을 i번째 포지션에 넣을지 말지 결정
		if (board[k][i] != 0 && !visit[i]) {
			visit[i] = 1;
			dfs(k + 1, sum + board[k][i]);
			visit[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		answer = 0; //능력치의 합
		memset(board, 0, sizeof(board)); 
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> board[i][j]; 
			}
		}
		dfs(0, 0);
		cout << answer << "\n";
	}

}