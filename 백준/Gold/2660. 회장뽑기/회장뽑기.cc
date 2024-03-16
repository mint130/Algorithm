#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
int n, m;
int ans = 0;
vector<int> v[52]; //정점 갯수만큼 vector list
int score[52] = { 0 };
int dist[52] = { 0 }; //가장 긴 거리
int main() {
	cin >> n;
	//n명
	
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1) break;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int ans = 987654321;
	for (int i = 1; i <= n; i++) {
		fill(dist, dist + 52, -1);
		//dist배열 초기화
		queue<int> q;
		q.push(i);
		dist[i] = 0;
		//정점 i에서 갈 수 있는 거리가 dist배열에 담김
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto nxt : v[cur]) {
				if (dist[nxt] >= 0) continue;
				q.push(nxt);
				dist[nxt] = dist[cur] + 1;
			}
		}

		int distMax = 0;
		for (int j = 1; j <= n; j++) {
			distMax = max(distMax, dist[j]);
		}
		//distMax는 i번째 정점에서 갈 수 있는 가장 긴 최단거리
		score[i] = distMax;
		//score[i]는 i번째 정점에서 가장 긴 최단거리 배열
		ans = min(score[i], ans); //ans는 최종 회장 후보 점수
	}
	vector<int> candidate;
	int cnt = 0; //후보의 수
	for (int i = 1; i <= n; i++) {
		if (score[i] == ans) { 
			cnt++; 
			candidate.push_back(i);
		}
	}
	cout << ans << " " << cnt << "\n";
	for (auto i : candidate) {
		cout << i << " ";
	}
}
