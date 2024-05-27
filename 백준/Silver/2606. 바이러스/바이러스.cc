#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n; //vertex 수
int e; //edge 수
bool visited[101];
int main() {
	cin >> n;
	vector<int> v[101];
	cin >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int ans = 0;
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		ans++;
		q.pop();
		for (int nxt : v[cur]) {
			if (!visited[nxt]) {
				visited[nxt] = 1;
				q.push(nxt);
			}
		}
	}
	cout << ans - 1;
}