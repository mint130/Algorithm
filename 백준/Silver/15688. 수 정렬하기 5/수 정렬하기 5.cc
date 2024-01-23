#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[1000002];
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}
	while (!pq.empty()) {
		cout<<pq.top()<<"\n";
		pq.pop();
	}
}