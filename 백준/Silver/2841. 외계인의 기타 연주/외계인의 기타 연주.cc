#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, p;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> p; //음의 수 n개, 프렛 수 p개
	stack<int> s[8]; //스택배열 
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int num, fret;
		cin >> num >> fret;
		while (!s[num].empty()) {
			if (s[num].top() > fret) {
				//현재 fret보다 같거나 작은 top이 나올 때까지 pop
				s[num].pop();
				ans++;
			}
			else if (s[num].top() == fret) {
				//아무것도 안 함
				break;
			}
			else if (s[num].top() < fret) {
				//프렛을 누름
				s[num].push(fret);
				ans++;
				break;
			}
			
		}
		if (s[num].empty()) {
			s[num].push(fret);
			ans++;
		}
		
	}
	cout << ans;
}