#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int T, A, B;
int dist[10001];
string ans[10001];
int main() {
	// D는 2*n, 결과값이 9999보다 크면 10000
	// S는 n-1, n이 0이면 9999 저장
	// L은 왼편으로(가장 왼쪽이 오른쪽으로 감)
	// R은 오른편으로(가장 오른쪽이 왼쪽으로)

	cin.tie(0);
	ios::sync_with_stdio();

	cin >> T;
	for (int tc = 1;tc <= T;tc++) {
		fill(dist, dist + 10001, -1); // 초기화
		fill(ans, ans + 10001, "");
		cin >> A >> B;

		queue<int> q;
		q.push(A);
		dist[A] = 0;
		ans[A] = "";
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur == B) {
				cout << ans[cur] << "\n";
				break;
			}
			// D
			int nxt = cur * 2;
			if (nxt > 9999) {
				nxt %= 10000;
			}
			if (dist[nxt] == -1) {
				dist[nxt] = dist[cur] + 1;
				ans[nxt] = ans[cur] + "D";
				q.push(nxt);
			}
			// S
			nxt = cur - 1;
			if (nxt < 0) nxt = 9999;
			if (dist[nxt] == -1) {
				dist[nxt] = dist[cur] + 1;
				ans[nxt] = ans[cur] + "S";
				q.push(nxt);
			}
			// L
			int first = cur / 1000; // 앞에 한자리
			int last = cur % 1000; // 뒤에 3자리
			nxt = last * 10 + first;
			if (nxt > 9999) {
				nxt %= 10000;
			}
			if (dist[nxt] == -1) {
				dist[nxt] = dist[cur] + 1;
				ans[nxt] = ans[cur] + "L";
				q.push(nxt);
			}
			// R
			last = cur / 10; // 앞에 3자리
			first = cur % 10; // 뒤에 1자리
			nxt = first * 1000 + last;
			if (dist[nxt] == -1) {
				dist[nxt] = dist[cur] + 1;
				ans[nxt] = ans[cur] + "R";
				q.push(nxt);
			}
		}
	}
	
}