#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;
int n;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}
	int ans = 0;
	if (pq.size() == 1)
	{
		ans = 0;
	}
	else {
		while (!pq.empty()) {
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			//맨 위에 두개가 빠짐
			int sum = a + b;
			ans += sum;
			if (pq.empty()) break;
			pq.push(sum);
		}
	}
	cout << ans;
	//cout << pq.top();
}