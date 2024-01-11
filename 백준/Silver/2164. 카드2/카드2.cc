#include <iostream>
#include <queue>

using namespace std;
int main() {

	int n;
	cin >> n;
	queue <int> q;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	//1부터 n까지 채움
	while (!q.empty()) {
		if (q.size() == 1) { break; }
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
	
}