#include <iostream>
#include <stack>

using namespace std;
int main() {

	string str;
	cin >> str;
	int laser = 0;
	int ans = 0;
	stack <char> s;
	for (int i = 0; i < str.length(); i++) {
		if (i != str.length() - 1 && str[i] == '(' && str[i + 1] == ')') {
			laser = 1;
		}
		if (str[i] == '(') s.push(str[i]);
		else {
			if (laser) {
				s.pop();
				ans = ans + s.size();
				laser = 0;
			}
			else {
				ans++;
				s.pop();
			}
		}
	}
	cout << ans;
}