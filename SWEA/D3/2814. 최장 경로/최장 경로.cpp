#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
using namespace std;
bool visited[11];
vector<int> adj[11];
int answer;

void dfs(int cur, int cnt) {
	if (cnt > answer) answer = cnt;
	visited[cur] = 1;
	for (auto nxt : adj[cur]) {
		if (!visited[nxt]) {
			visited[nxt] = 1;
			dfs(nxt, cnt + 1);
			visited[nxt] = 0;
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;


	for (int tc = 1; tc <= T; tc++) {
		int n, m;
		answer = 0;
		
		cin >> n >> m;
		for (int i = 0; i < 11; i++) {
			adj[i].clear();
		}
		fill(visited, visited + 11, 0);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			//i번에서 갈 수 있는 점들 dfs
            if(!visited[i]) {
                visited[i]=1;
                dfs(i, 1);
            	visited[i]=0;
            }
            
		
		}
		cout << "#" << tc << " " << answer << "\n";
	}
	
}