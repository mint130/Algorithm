#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
using namespace std;
int answer;
int n, m;
int arr[1002]; 
bool isused[1002];
void dfs(int cnt, int sum, int idx) {
	//idx는 쓰인 숫자
	if (cnt == 2) {
		if (sum < m) answer = max(sum, answer);
		else if (sum > m) answer = -1;
		else answer = sum;
		return;
	}
	for (int i = idx; i < n; i++) {
		if (!isused[i]) {
			isused[i] = 1;
			if (sum + arr[i] <= m) dfs(cnt + 1, sum + arr[i], i);
			isused[i] = 0;
		}
	}

	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		answer = -1;
		cin >> n >> m;
		fill(arr, arr + 1002, 0);
		fill(isused, isused + 1002, 0);
		//n은 과자 봉지 갯수
		//m은 무게 제한 
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		dfs(0, 0, 0);
		cout << "#" << tc << " " << answer << "\n";
	
	}
}