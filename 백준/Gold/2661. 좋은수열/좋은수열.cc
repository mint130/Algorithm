#include <iostream>

using namespace std;
int n;
bool endflag = false;
int arr[82];
bool check(string s) {

	int len = s.length();
	//뒤에서부터 1부터 len까지 
	for (int i = 1; i <= (len / 2); i++) {
		//뒤에서부터 검사
		if (s.substr(len - i, i) == s.substr(len - 2 * i, i)) {
			return false;
		}
	}
	return true;
	

}
void func(int depth, string s) {
	if (endflag) return;
	if (!check(s)) return;
	if (depth == n) {
		cout << s;
		endflag = true;
		return;
	}
	
	func(depth + 1, s + '1');
	func(depth + 1, s + '2');
	func(depth + 1, s + '3');
	
}
int main() {
	//123으로 만들 수 있는 수열
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	string ans = "";
	func(0, ans);
}