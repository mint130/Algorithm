#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, x, y; //n 집 m 양방향 도로 x 하루에 걸을 수 있는 거리 y 성현이 집
int d[1001]; // y부터 1~n-1까지의 거리
vector<pair<int, int>> v[1001];  // v[a].push_back({거리, b})
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 거리, 도착점
int ans = 0;
int main() {
	cin >> n >> m >> x >> y;
	fill(d, d + 1001, 987654321); // 초기화
	d[y] = 0;
	pq.push({ 0, y });

	for (int i = 0;i < m;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ c, b }); // b는 도착점 c는 거리
		v[b].push_back({ c, a });
	}

	while (!pq.empty()) {
		int cur = pq.top().second;
		int dist = pq.top().first;
		pq.pop();
		if (d[cur] != dist) continue;
		for (auto nxt : v[cur]) {
			if (d[nxt.second] > dist + nxt.first) {
				d[nxt.second] = dist + nxt.first;
				pq.push({ d[nxt.second], nxt.second });
			}
		}
	}
	sort(d, d + n);
	for (int i = 0;i < n;i++) {
		if (d[i] * 2 > x || d[i] == 987654321) { 
			//아예 갈 수 없거나 왕복거리가 무조건 x보다 큰 경우 
			cout << -1;
			return 0;
		}
	}
	int tmp = 0; // 하루동안 걷는 거리
	int idx = 0;
	while (idx < n) {
		while (tmp + 2 * d[idx] <= x) {
			tmp += 2 * d[idx];
			idx++;
		}
		tmp = 0;
		ans++;
	}
	cout << ans;
}