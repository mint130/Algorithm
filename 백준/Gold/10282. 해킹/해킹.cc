#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int tc, n, d, c, num, t;
int dist[10001];
vector<pair<int, int>> v[10001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> tc;
	for (int i = 0;i < tc;i++) {
		num = 0;
		t = 0;
		cin >> n >> d >> c; //컴퓨터 갯수,	의존성 갯수, 해킹당한 컴퓨터 번호
		//c부터 시작
		fill(dist, dist + n+1, 987654321);
		for (int j = 1;j <= d;j++) {
			int a, b, s;
			cin >> a >> b >> s; //a가 b를 의존 -> b가 감염되면 s초 후 a도 감염
			v[b].push_back({ s, a });
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0, c });
		dist[c] = 0;
		while (!pq.empty()) {
			int cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			if (dist[cur] != cost) continue;
			
			for (auto nxt : v[cur]) {
				if (nxt.first + cost < dist[nxt.second]) {
					dist[nxt.second] = nxt.first + cost;
					pq.push({dist[nxt.second], nxt.second});
				}
			}
		}

		for (int i = 1;i <= n;i++) {
			v[i].clear();
			if (dist[i] != 987654321) {
				t = max(t, dist[i]);
				num++;
			}
		}

		cout << num <<" "<< t << "\n"; //컴퓨터 수, 걸리는 시간

	}
}