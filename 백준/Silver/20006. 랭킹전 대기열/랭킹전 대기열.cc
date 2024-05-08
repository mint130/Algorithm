#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
using namespace std;
bool cmp(pair<int, string> &p1, pair<int, string> &p2) {
	return p1.second < p2.second;

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//매칭은 처음 플레이어 기준 -10부터 +10까지
	//입장 가능한 방이 있다면 모두 찰 때까지 대기
	//입장 가능한 방이 여러개라면 먼저 생성된 방에 입장
	//정원이 모두 차면 게임 시작
	int p, m;
	cin >> p >> m;
	vector<pair<int, string>> v[301]; //v[i].size()가 m이여야함
	int idx = 0; //방의 인덱스

	for (int i = 0; i < p; i++) {
		int lv;
		string n;
		cin >> lv >> n;
	
		bool find = 0;
		//방의 첫번째 플레이어와 비교해서 넣어줌
		for (int k = 0; k < idx; k++) {

			int first_lv = v[k][0].first;
			//cout << k<<" "<<first_lv << endl;
			if (v[k].size() != m) {
				if (lv <= first_lv + 10 && lv >= first_lv - 10) {
					v[k].push_back({ lv, n });
					find = 1;
					break;
				}
			}
			
		}
		if (!find) {
			//새로 방을 만들어야함
			v[idx].push_back({ lv, n });
			idx++;
		}
	}
	for (int i = 0; i < idx; i++) {
		if (v[i].size() < m) cout << "Waiting!" << "\n";
		else cout << "Started!" << "\n";
		sort(v[i].begin(), v[i].end(), cmp);
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j].first << " " << v[i][j].second << "\n";
		}
	}
}