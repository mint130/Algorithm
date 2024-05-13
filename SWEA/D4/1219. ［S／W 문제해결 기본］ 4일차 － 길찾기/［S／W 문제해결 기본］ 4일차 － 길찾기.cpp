#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
bool visited[101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 10;
	for (int tc = 1; tc <= T; tc++) {
		int answer = 0;
		fill(visited, visited + 101, 0);
		vector<int> adj[101];
		int m, n;
		cin >> m >> n;
		for (int i = 0; i < 2*n;  i=i+2) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}
		//출발은 0, 도착은 99
		queue<int> q;
		q.push(0);
		visited[0] = 1;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur == 99) {
				//도착
				answer = 1;
				break;
			}
			for (auto nxt : adj[cur]) {
				if (!visited[nxt]) {
					visited[nxt] = 1;
					q.push(nxt);
				}
			}
		}
		cout << "#" << tc << " " << answer<<"\n";
	}
}