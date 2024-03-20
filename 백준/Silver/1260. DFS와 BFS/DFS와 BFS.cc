#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int n, m, v;
vector <int> vertex[1002];
bool visit[1002];
void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = 1;
	cout << v << " ";
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		sort(vertex[cur].begin(), vertex[cur].end());
		for (auto nxt : vertex[cur]) {
			if (visit[nxt]) continue;
			cout << nxt << " ";
			q.push(nxt);
			visit[nxt] = 1;
		}
	}
}

void dfs(int cur) {
	cout << cur << " ";
	visit[cur] = 1;
	sort(vertex[cur].begin(), vertex[cur].end());
	for (auto nxt : vertex[cur]) {
		if (visit[nxt]) continue;
		dfs(nxt);
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vertex[a].push_back(b);
		vertex[b].push_back(a);
	}
	dfs(v);
	cout << "\n";
	fill(visit, visit + 1002, 0);
	bfs(v);
}