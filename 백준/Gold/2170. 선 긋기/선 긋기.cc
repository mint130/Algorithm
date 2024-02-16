#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<pair<long long, long long>> v;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end());
	
	long long ans = 0;
	long long st, en = -1000000001;
	for (int i = 0; i < n; i++) {
		if (v[i].first > en) {
			//겹치지 않는 경우
			ans += v[i].second - v[i].first;
			st = v[i].first;
			en = v[i].second;
		}
		else if (v[i].first>=st && v[i].second<=en) {
			//완전히 겹치는 경우
			continue;
		}
		else if(v[i].first>=st && v[i].second>en) {
			//일부 겹치는 경우
			ans += v[i].second - en;
			en = v[i].second;
		}
	}
	cout << ans;
}