#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string.h>
#include <tuple>
#include <queue>
using namespace std;

int v, e;
int st;
int d[20002]; //최단 거리 테이블
const int INF = 987654321;
vector<pair<int, int>> adj[20002]; //비용, 정점

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> v >> e;
	cin >> st;
	fill(d, d + v + 1, INF); //INF로 초기화
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	//st부터의 최단거리 비용, 정점 넣음
	pq.push({ 0, st });
	d[st] = 0;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		//a->b에 c 간선
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}
	while (!pq.empty()) {
		int cost, cur;
		cost = pq.top().first;
		cur = pq.top().second;
		pq.pop();

		if (d[cur] != cost) continue; //일치하지 않으면 해당원소 제거하고 넘어감
		//현재 정점 에서 갈 수 있는 정점 찾기
		for (auto nxt : adj[cur]) {
			//nxt.second가 정점, nxt.first가 비용
			if (cost + nxt.first < d[nxt.second]) {
				d[nxt.second] = cost + nxt.first;
				pq.push({ d[nxt.second], nxt.second});
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF" << "\n";
		else cout << d[i] << "\n";
	}
	
}	