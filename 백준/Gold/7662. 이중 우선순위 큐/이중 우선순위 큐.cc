#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;
int m, n;
int t;
int main() {
	cin >> t;
	
	//n은 포켓몬의 갯수, m은 맞춰야 하는 문제의 갯수
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int tc = 0; tc < t; tc++) {
		multiset <int, greater<int>> s;
		//우선순위가 가장 높거나 낮은 것 삭제
		//우선순위가 높으면 맨 앞
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			
			if (c == 'I') {
				int num;
				cin >> num;
				s.insert(num);	
			}
			else {
				int num;
				cin >> num;
				if (s.empty()) continue;
				if (num == 1) {
					//최댓값 삭제
					s.erase(s.begin());
				}
				else {
					//최솟값 삭제
					s.erase(prev(s.end()));
				}
			}
		}
		
		if (s.empty()) cout << "EMPTY" << "\n";
		else cout << *s.begin() << " " << *prev(s.end()) << "\n";
	}
	
}