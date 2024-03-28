#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string.h>
#include <tuple>
#include <queue>
using namespace std;
int dp[102][102];
int nxt[102][102];
int n, m;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = 987654321;
		}
	}
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b], c);
		nxt[a][b] = b;
		
	}
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0;
		nxt[i][i] = 0;
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == 987654321) dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (dp[i][j] == 0) cout << 0 << "\n";
			if (nxt[i][j] == j) cout << 2 << " " << i << " " << j << "\n";
			else {
				vector<int> v;
				int cnt = 2;
				v.push_back(i);
				int dest = nxt[i][j];
				v.push_back(dest);
				while (1) {
					if (nxt[dest][j] == j) {
						v.push_back(j);
						cnt++;
						break;
					}
					dest = nxt[dest][j];
					v.push_back(dest);
					cnt++;
				}
				cout << cnt << " ";
				for (auto k : v) {
					cout << k << " ";
				}
				cout << "\n";
			}
		}
	}
	*/


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == 0) {
				cout << 0 << "\n";
				continue;
			}

			vector<int> v;
			
			int st = i;
			while (st != j) {
				v.push_back(st);
				st = nxt[st][j];
			}
			v.push_back(j);
			cout << v.size() << " ";
			for (auto k : v) {
				cout << k << " ";
			}
			cout << "\n";
		}
	}
	//i->j로 가는 경로 출력 : 경로에 있는 k 갯수/ 경로
	//ex) 2->3
	//5개: 2 > 4 > 5 > 1 > 3
}