#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <tuple>
#include <queue>
using namespace std;


int n;
int ans = 0; //최소 스패닝 트리의 비용
int cnt = 0; //최소 스패닝 트리 간선 갯수 (v-1일때 종료)

vector<pair<int, int>> adj[302]; //비용, 정점
bool chk[302]; //i번째 정점이 포함되어 있는가
//0부터 시작
//tuple은 비용 정점1 정점 2
priority_queue < tuple<int, int, int>,
	vector<tuple<int, int, int>>,
	greater<tuple<int, int, int>> > pq;
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		adj[i].push_back({ num, n + 1 });
		adj[n + 1].push_back({ num, i });
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			
			adj[i].push_back({ num, j });
		}
	}
	chk[0] = 1;
	//정점 및 간선 입력 받음
	for (auto nxt : adj[0]) {
		pq.push({ nxt.first, 0, nxt.second });
	}
	//우선순위 큐에 간선 추가 {비용, 정점(minidx), 이어진 정점)
	while (cnt < n) {
		int cost, a, b;
		tie(cost, a, b) = pq.top(); pq.pop();
		//우선순위 큐에 있던 비용이 제일 적은 간선 빼냄
		if (chk[b]) continue; //최소 스패닝 트리에 있는지 여부확인
		chk[b] = 1; 
		cnt++;
		ans += cost;
		//최소 스패닝 트리에 추가
		for (auto nxt : adj[b]) {
			//nxt 중 최소 스패닝 트리에 연결되지 않은 정점이 있다면 간선 우선순위 큐에 추가
			if (!chk[nxt.second]) pq.push({ nxt.first, b, nxt.second });
		}
	}

	cout << ans;
}