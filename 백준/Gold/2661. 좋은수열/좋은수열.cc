#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n;
string ans;
bool check(string s) {
	// 좋은 수열인지 판단
	int len = s.length();
	for (int i = 1; i <= len / 2; i++) {
		// 뒤에서부터 i만큼
		string tmp1 = s.substr(len - i, i);
		// len-i보다 i만큼 더 앞으로
		string tmp2 = s.substr(len - (2 * i), i);
		if (tmp1 == tmp2) return false; // 나쁜 수열 포함
	}
	return true;
}
void dfs(int idx, string s) {
	if (!check(s)) return;
	if (idx == n) {
		cout << s;
		exit(0); // 가장 첫번쨰만 출력하고 끝
	}
	dfs(idx + 1, s + '1');
	dfs(idx + 1, s + '2');
	dfs(idx + 1, s + '3');
}
int main() {
	cin >> n;
	dfs(0, "");
}