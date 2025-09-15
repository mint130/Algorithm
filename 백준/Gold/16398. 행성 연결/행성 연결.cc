#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
bool visited[1001];
vector<pair<int, int>> v[1001]; // 비용, 도착점
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			if (i < j) {
				v[i+1].push_back({ num, j+1 });
				v[j+1].push_back({ num, i+1 });
			}
		}
	}
	
	pq.push({ 0, 1 }); // cost, 목적지
	long long ans = 0;
	while (!pq.empty()) {
		long long cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (visited[cur]) continue;
		visited[cur] = 1;
		ans += cost;
		for (auto nxt : v[cur]) {
			if (!visited[nxt.second]) {
				pq.push({ nxt.first, nxt.second }); // cost, 목적지
			}
		}
	}
	cout << ans;
}