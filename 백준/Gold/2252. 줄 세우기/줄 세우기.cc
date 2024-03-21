#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int n, m;
vector<int> v[32002]; //indegree 배열
int deg[32002]; //indegree갯수
vector<int> result; //결과
queue<int> q; //indegree가 없는 idx 큐에 넣음
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		deg[b] ++;
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		result.push_back(cur);
		for (auto nxt : v[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}

	}
	for (auto x : result) cout << x << " ";
}