#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string.h>
#include <cstring>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int tc = 1; tc <= 10; tc++) {
		int answer = 0;
		int n;
		cin >> n; //덤프 횟수

		priority_queue<int, vector<int>> pq1; //내림차순 우선순위 큐
		priority_queue<int, vector<int>, greater<int>> pq2; //오름차순 우선순위 큐
		for (int i = 1; i <= 100; i++) {
			int num;
			cin >> num;
			pq1.push(num);
			pq2.push(num);
		}

		for (int i = 0; i < n; i++) {
			int max = pq1.top();
			pq1.pop();
			pq1.push(max - 1);
			int min = pq2.top();
			pq2.pop();
			pq2.push(min + 1);
        }
		answer = pq1.top() - pq2.top();
		cout << "#" << tc << " " << answer << "\n";
	}
	
}