#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		priority_queue<int> pq;
		queue<pair<int,int>> q;
		int cnt = 0;
		int n, m;
		cin >> n >> m;
		for (int idx = 0; idx < n; idx++) {
			int value;
			cin >> value;
			q.push({ idx, value }); //idx, 중요도
			pq.push(value); //중요도
		}
		
		while (!q.empty()) {
			int idx = q.front().first;
			int value = q.front().second;
			q.pop();
			//중요도가 높은 문서는 pq에 순서대로 있음
			if (value == pq.top()) {
				pq.pop();
				cnt++;
				if (idx == m) {
					cout << cnt << "\n";
				
				}
			}
			else {
				q.push({ idx, value });
			}


		}
	}
	
}