#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string.h>
#include <cstring>

using namespace std;
int d[1002]; //최소 비용이 들어감
vector<pair<int, int>> adj[1002]; //{비용, 정점}
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{비용, 정점}
int arr[100000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n; //1부터 n까지 정점
	cin >> m;
	fill(d, d + n + 1, 987654321); //최소비용 초기화 
	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a].push_back({ cost, b });
	}
	int st, en;
	cin >> st >> en;
	d[st] = 0;
	pq.push({ 0, st });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cost != d[cur]) continue; //우선순위 큐로 규현했기 때문에 cost가 d[cur]과 일치하지 않음=이미 cur의 최소비용이 d[cur]에 반영
		for (auto nxt : adj[cur]) {
			//nxt.first가 비용, nxt.second가 정점
			if (nxt.first + cost < d[nxt.second]) {
				d[nxt.second] = nxt.first + cost;
				pq.push({ d[nxt.second], nxt.second });
			}
		}
	}
	cout << d[en];
}