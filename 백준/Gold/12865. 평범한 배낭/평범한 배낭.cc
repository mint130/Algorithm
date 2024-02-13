#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> a;
int n, k;
int dp[102][100002]; //배낭에 넣는 물건 번호/무게
int w[102];
int v[102];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	//베낭 용량이 0
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}
	//어떤 물건도 담지 않음
	for (int i = 0; i <= k; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			//물건 i를 베낭에 담지 않는 경우 dp[i][j]=dp[i-1][j]
			//물건 i를 베낭에 담는 경우 현재 용량이 j-w[i]인 경우의 최대 가치 + v[i] 
			//j는 베낭 무게
			if (j < w[i]) {
				//베낭보다 현재 물건 i의 무게가 더 크면 담지 않음
				dp[i][j] = dp[i - 1][j];
			}
			else {
				//현재 물건 i를 담지 않거나 담거나
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	cout << dp[n][k];
	
}