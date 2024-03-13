#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <set>


using namespace std;
int n, k;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k; //보석 n, 가방 k
	long long ans = 0;
	vector<pair<int, int>> v1;
	vector<int> v2;

	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		v1.push_back({ m, v });
	}
	sort(v1.begin(), v1.end());
	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		v2.push_back(c);
	}
	sort(v2.begin(), v2.end());
	//가방 크기가 작은 것부터 보석을 채움
	priority_queue<int> pq;
	int idx = 0;
	for (int i = 0; i < v2.size(); i++) {
		//v2[i]에 가방의 크기가 있음
		//v1 first가 v2[i]보다 작거나 같은 값들을 pq에 넣어 pq의 top에 있는 값 ans에 추가
		int bag = v2[i];
		while (idx < n && v1[idx].first <= bag) {
			pq.push(v1[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}


	cout << ans;

}