#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string.h>
#include <tuple>
#include <queue>
using namespace std;

int n, e;
int st, en;
int d[20002]; //최단 거리 테이블
int pre[20002];
const int INF = 987654321;
vector<pair<int, int>> adj[20002]; //비용, 정점

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> e;
	
	fill(d, d + n + 1, INF); //INF로 초기화
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	//st부터의 최단거리 비용, 정점 넣음
	
	for (int i = 0; i < e; i++) {
		int a, b, c;
		//a->b에 c 간선
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });

	}

	cin >> st >> en;
	d[st] = 0;
	pq.push({ 0, st });
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
				d[nxt.second] = cost + nxt.first; //cost==d[cur]
				pre[nxt.second] = cur;
				pq.push({ d[nxt.second], nxt.second });
			}
		}
	}
	cout << d[en] << "\n"; //출발도시에서 도착도시까지 드는 최소 비용

	int ans = 0;
	vector<int>  v;
	int cur = en;
	while (cur != st) {
		v.push_back(cur);
		cur = pre[cur];
	}
	v.push_back(cur);
	reverse(v.begin(), v.end());
	cout << v.size() << "\n"; //최소비용 갖는경로에 포함된 도시 갯수
	for (auto i : v) {
		cout << i << " ";
	}


}