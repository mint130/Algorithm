#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second != p2.second) return p1.second < p2.second;
	else if (p1.second == p2.second) return p1.first < p2.first;
}
int main() {
	//시작 시간이 t이상인 모든 회의 중에서 가장 먼저 끝나는 회의 선택
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start;
		int end;
		cin >> start >> end;
		v.push_back({ start, end });
	}
	//시작 시간이 빠른 순으로 정렬
	sort(v.begin(), v.end(), cmp);

	int st = 0;
	int en = 0;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		
		if (v[i].first >= en) {
			st = v[i].first;
			en = v[i].second;
			cnt++;
		}
		
	}
	cout << cnt;
}