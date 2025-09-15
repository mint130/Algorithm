#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<double, double>> v;
bool visited[101]; // i번째 별에 방문
//priority_queue < pair<double, pair<double, double>>, vector<pair<double, pair<double, double>>>, greater<>> pq;
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq; // 거리, 번호
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		double d1, d2;
		cin >> d1 >> d2;
		v.push_back({ d1, d2 });
	}
	sort(v.begin(), v.end());
	pq.push({ 0, 0 });
	double ans = 0;
	while (!pq.empty()) {
		double dist = pq.top().first;
		int cur = pq.top().second;

		pq.pop();	
		if (visited[cur]) continue;
		visited[cur] = 1;

		ans += dist; // 거리 더함
		// 현재 좌표 x, y
		double x = v[cur].first;
		double y = v[cur].second; 
		for (int nxt = 0; nxt < n; nxt++) {
			if (cur == nxt) continue;
			if (visited[nxt]) continue;
			double d1 = pow(abs(v[nxt].first - x),2);
			double d2 = pow(abs(v[nxt].second - y),2);
			// cur과 nxt 좌표 사이의 거리 구함
			pq.push({ sqrt(d1 + d2), nxt });

		}
	}
	cout.precision(2);
	cout << fixed << ans;
}	