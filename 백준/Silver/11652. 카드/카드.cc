#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int n;
map<long long, long long> m;

bool cmp(pair<long long, long long> &a, pair<long long, long long> &b) {
	//pair의 second(빈도수)가 작은<큰
	//pair의 second가 같다면 first가 작은<큰
	if (a.second != b.second) return a.second > b.second;
	else {
		if (a.first != b.first) return a.first < b.first;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		m[num]++;
	}
	//가장 많이가지고 있는..
	vector<pair<long long, long long>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	//sort(m.begin(), m.end(), cmp);
	//for (int i = 0; i < v.size(); i++) {
	//	cout << v[i].first<<" "<<v[i].second << "\n";
	//}
	cout << v[0].first;
	
}