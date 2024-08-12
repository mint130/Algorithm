#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int n, d;
vector<pair<int, int>> v[10001]; //v[끝점].push_back({도착점, 길이})
int dp[10001]; //dp[i]는 i까지 가는데 걸리는 거리
int main() {
	cin >> n >> d;
	//d가 목적지 위치
	for (int i = 0; i < n; i++) {
		int st, en, len;
		cin >> st >> en >> len;
		if (en > d) continue; //역주행 불가
		v[en].push_back({ st, len });
	}
	
	//지름길이 있는 시작점은 v[i].size()==0
	for (int i = 1; i <= d; i++) {
		dp[i] = dp[i - 1] + 1;
		for (auto j : v[i]) {
			//도착이 i인 지름길 j가 있다면
			dp[i] = min(dp[i], dp[j.first] + j.second);
			//지름길의 시작점+길이와 현재 dp 비교해서 작은 값 저장
		}
	}
	cout << dp[d];
}