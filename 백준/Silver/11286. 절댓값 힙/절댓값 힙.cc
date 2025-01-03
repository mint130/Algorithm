#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;
int n;
struct compare {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) return a > b;
		else return abs(a) > abs(b);
	}
};
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	priority_queue<int, vector<int>, compare> pq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x != 0) {
			pq.push(x);
		}
		else {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}
}