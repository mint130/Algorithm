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
int n;
vector<int> ans;
bool check(int k) {
	if (k <= 2) return false;
	for(int i=2;i*i<=k;i++){
		if (k % i == 0) return false;
	}
	return true;
}
void dfs(int num, int len) {
	//숫자, 자리수
	//자리수가 n이 되면 중단 
	if (len == n) {
		ans.push_back(num);
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (check(num * 10 + i)) {
			dfs(num * 10 + i, len + 1);
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; //n자리의 숫자들 중 신기한 소수 고르기
	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);

	for (auto i : ans) {
		cout << i << "\n";
	}

	
}