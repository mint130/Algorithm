#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
using namespace std;
bool board[101][101]; //board[from][to]가 1이면 이미 있음
int dist[101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 10;
	for (int tc = 1; tc <= T; tc++) {
		int n, st;
		cin >> n >> st;
		int answer = 0;
		fill(dist, dist + 101, -1); //거리
		memset(board, 0, sizeof(board));
		vector<int> adj[101];
		for (int i = 0; i < n - 1; i = i + 2) {
			int from;
			int to;
			cin >> from >> to;
			if (board[from][to]) continue; //중복은 넣지 않음
			adj[from].push_back(to);
		}
		queue<int> q;
		q.push(st);
		dist[st] = 0;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			//현재 노드
			for (auto nxt : adj[cur]) {
				if (dist[nxt] == -1) {
					//아직 방문하지 않음
					dist[nxt] = dist[cur] + 1;
					q.push(nxt);
				}
			}
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
		for (int i = 1; i <= 100; i++) {
			if (dist[i] != -1) {
				//i는 idx, dist[i]는 거리
				//거리가 높은 것 중 idx가 가장 큰 것
				pq.push({ dist[i], i });
			}
		}
		answer = pq.top().second;
		cout << "#" << tc << " " << answer << "\n";
	}
}