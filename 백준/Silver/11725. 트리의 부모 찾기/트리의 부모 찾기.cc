#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int n;
int par[100002]; //노드의 부모
vector<int> v[100002]; //양방향 그래프
void bfs(int root) {

	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : v[cur]) {
			if (nxt == par[cur]) continue;
			par[nxt] = cur;
			q.push(nxt); //다음 방문할 정점의 부모는 현재 정점
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs(1);
	for (int i = 2; i <= n; i++) {
		cout << par[i] << "\n";
	}
}