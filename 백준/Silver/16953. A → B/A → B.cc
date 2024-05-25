#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
long long a, b;

int main() {
	//a->b
	//*2, 1을 수의 가장 오른쪽에 추가
	cin >> a >> b;
	queue<pair<long long, int>> q;
	q.push({ a, 0 });
	while (!q.empty()) {
		long long cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == b) {
			cout << cnt + 1;
			return 0;
		}
		if (cur*2 <= b) {
			q.push({ cur * 2, cnt + 1 });
		}
		if (cur * 10 + 1 <= b) {
			q.push({ cur * 10 + 1, cnt + 1 });
		}
		
	}
	cout << -1;
}