#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
long long a, b;

int main() {
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
		long long nxt = cur * 2;
		if (nxt <= b) {
			q.push({ nxt, cnt+1 });
		}
		nxt = cur * 10 + 1;
		if (nxt <= b) {
			q.push({ nxt, cnt + 1 });
		}
	}
	cout << -1;
}