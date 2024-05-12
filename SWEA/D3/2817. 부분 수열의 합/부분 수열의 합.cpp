#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
int arr[22];
int k;
int answer;
int n;
void dfs(int sum, int idx) {
	//i번째 수를 넣을지 말지 결정
	if (idx == n) {
		if (sum == k) answer++;
		return;
	}

	dfs(sum, idx + 1); //idx번째 수를 넣지 않음
	dfs(sum + arr[idx], idx + 1); //idx번째 수를 넣음
}
int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> k; //갯수 n, 합이 k
		answer = 0; //경우의 수 갯수
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		dfs(0, 0);
		cout << "#" << tc << " " << answer << "\n";
		
	}

}