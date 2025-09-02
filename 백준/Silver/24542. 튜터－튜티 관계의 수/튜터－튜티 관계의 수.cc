#include <iostream>
#include <vector>
using namespace std;
bool visited[200001];
vector<int> v[200001];
int n, m;
long long ans = 1;
int cnt = 1;
void dfs(int cur) {
	for (auto nxt : v[cur]) {
		if (!visited[nxt]) {
			visited[nxt] = 1;
			cnt++;
			dfs(nxt);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		cnt = 1;
		visited[i] = 1;
		dfs(i);
		ans = (ans * cnt) % 1000000007;
	}
	cout << ans;
}