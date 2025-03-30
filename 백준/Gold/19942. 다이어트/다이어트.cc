#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;
int N, P, F, S, V;
int ans = 987654321;
int arr[16][5];
bool used[16];
set<int> ansset;
void dfs(int cur, int sumP, int sumF, int sumS, int sumV, int cost) {
	if (cost > ans) return;
	if (sumP >= P && sumF >= F && sumS >= S && sumV >= V) {
		set<int> s;
		for (int i = 0;i < N;i++) {
			if (used[i]) {
				s.insert(i + 1);
				//cout << i + 1 << " ";
			}
		}
		if (ansset.empty()) { ansset = s; }
		else {
			if (cost < ans) {
				ansset = s;
			}
			else if (cost == ans) {
				// 기존 cost와 같으면 사전 순으로 가장 빠른 것
				if (s < ansset) ansset = s;
			}
		}
		ans = cost;
		return;
	}
	for (int i = cur;i < N;i++) {
		if (!used[i]) {
			used[i] = 1;
			// i번째 선택;
			dfs(i+1, sumP + arr[i][0], sumF + arr[i][1], sumS + arr[i][2], sumV + arr[i][3], cost + arr[i][4]);
			used[i] = 0;
			// i번째 선택 x
			dfs(i + 1, sumP, sumF, sumS, sumV, cost);
		}
		
	}
	
	
}
int main() {
	cin >> N;
	//p: 단백질, f: 지방, s: 탄수화불 v: 비타민, c: 가격
	cin >> P >> F >> S >> V;
	for (int i = 0;i < N;i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];
	}
	dfs(0, 0, 0, 0, 0, 0);
	if (ans == 987654321) { cout << -1; return 0; }
	cout << ans << "\n";
	for (auto i : ansset) {
		cout << i << " ";
	}

}