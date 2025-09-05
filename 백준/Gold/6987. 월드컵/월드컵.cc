#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[4][6][3]; // 6개국 승 무 패
vector<pair<int, int>> games;
int score[6][3]; // 6개국 승 무 패
bool flag = 0;
void dfs(int cnt, int tc) {
	if (flag) {
		return;
	}
	if (cnt == 15) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				// 아닌 숫자가 있으면 return
				if (arr[tc][i][j] != score[i][j]) return;
			}
		}
		// 모든 경우의 수가 다 일치함
		flag = 1;
		return;
	}
	int a = games[cnt].first;
	int b = games[cnt].second;

	// a승 b패
	score[a][0]++;
	score[b][2]++;
	if (arr[tc][a][0] >= score[a][0] && arr[tc][b][2] >= score[b][2])
		dfs(cnt + 1, tc);
	score[a][0]--;
	score[b][2]--;

	// a패 b승
	score[b][0]++;
	score[a][2]++;
	if(arr[tc][a][2] >= score[a][2] && arr[tc][b][0] >= score[b][0])
		dfs(cnt + 1, tc);
	score[a][2]--;
	score[b][0]--;

	// 비김
	score[a][1]++;
	score[b][1]++;
	if(arr[tc][a][1] >= score[a][1] && arr[tc][b][1] >= score[b][1])
		dfs(cnt + 1, tc);
	score[a][1]--;
	score[b][1]--;
}
int main() {
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			games.push_back({ i, j });
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> arr[i][j][k];
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		memset(score, 0, sizeof(score));
		flag = 0;
		dfs(0, i);
		if (flag) cout << 1<<" ";
		else cout<<0<<" ";
	}

}