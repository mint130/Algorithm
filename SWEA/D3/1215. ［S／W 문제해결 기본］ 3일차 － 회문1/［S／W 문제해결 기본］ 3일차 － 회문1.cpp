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

char board[9][9];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 10;
	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;
		int answer = 0;

		for (int i = 0; i < 8; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 8; j++) {
				board[i][j] = s[j];
			}
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 8 - n; j++) {
				vector <char> v1;
				vector<char> v2;
				//행
				for (int len = 0; len < n; len++) {
					v1.push_back(board[i][j + len]);
					v2.push_back(board[i][j + len]);
				}
				reverse(v2.begin(), v2.end());
				if (v1 == v2) answer++;
			}
		}
		for (int i = 0; i <= 8 - n; i++) {
			for (int j = 0; j < 8; j++) {
				vector <char> v1;
				vector<char> v2;
				//열
				for (int len = 0; len < n; len++) {
					v1.push_back(board[i + len][j]);
					v2.push_back(board[i + len][j]);
				}
				reverse(v2.begin(), v2.end());
				if (v1 == v2) answer++;
			}
		}
		cout << "#" << tc << " " << answer << "\n";
	}

}