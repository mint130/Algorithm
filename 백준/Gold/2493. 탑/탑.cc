#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<pair<int, int>> s;
	for (int i = 0; i < n; i++) {
		int height;
		cin >> height;
		while (!s.empty()) {
			if (s.top().second> height) {
				cout << s.top().first << " ";
				break;
			}
			//스택의 top이 현재 입력받은 탑 높이보다 크면 수신 가능하므로 출력
			s.pop(); 
			//수신 가능한 탑이 나올 때까지 pop
		}
		
		if (s.empty()) {
			cout << "0 ";
		}
		//스택이 비었으면 0 출력
		s.push({ i + 1, height });
		//스택에 순서와 탑 높이를 같이 넣는다
	}
	
}