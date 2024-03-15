#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;
int n, m;
int ans = 0;
vector<int> g[1001]; //정점 갯수만큼 vector list
bool visited[1001];
void BFS(int vertex) {
	queue<int> q;
	visited[vertex] = 1;
	q.push(vertex);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : g[cur]) {
			if (visited[nxt]) continue;
			q.push(nxt);
			visited[nxt] = true;
		}

	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			BFS(i);
			ans++;
		}
	}
	cout << ans;
}