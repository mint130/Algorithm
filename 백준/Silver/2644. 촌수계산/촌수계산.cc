#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b;
int dist[101];
vector<int> v[101];

int main() {
	cin >> n;
	cin >> a >> b;
	cin >> m;

	int ans = 0;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);

	}
	fill(dist, dist + 101, -1);
	queue<int> q;
	q.push(a);
	dist[a] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == b) {
			break;
		}
		for (int nxt : v[cur]) {
			if (dist[nxt] == -1) {
				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
			}
		}
	}
	cout << dist[b];
}