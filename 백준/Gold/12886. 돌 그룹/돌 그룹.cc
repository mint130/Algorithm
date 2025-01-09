#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int A, B, C;
bool visit[500][500]; //min과 max만

int main() {
	cin >> A >> B >> C;
	vector<int> v;
	v.push_back(A); v.push_back(B); v.push_back(C);
	sort(v.begin(), v.end());
	queue<vector<int>> q;
	q.push(v);
	visit[v[0]][v[2]] = 1;
	while (!q.empty()) {
		vector<int> cur = q.front();
		int a = cur[0];
		int b = cur[1];
		int c = cur[2];
		q.pop();
		if (a == b && b == c) {
			cout << 1;
			return 0;
		}
		if (b - a >= 0) {
			int x = a * 2;
			int y = b - a;
			int z = c;
			vector<int> nxt;
			nxt.push_back(x);
			nxt.push_back(y);
			nxt.push_back(z);
			sort(nxt.begin(), nxt.end());
			if (!visit[nxt[0]][nxt[2]]) {
				visit[nxt[0]][nxt[2]] = 1;
				q.push(nxt);
			}
		}
		if (c - a >= 0) {
			int x = a * 2;
			int y = c - a;
			int z = b;
			vector<int> nxt;
			nxt.push_back(x);
			nxt.push_back(y);
			nxt.push_back(z);
			sort(nxt.begin(), nxt.end());
			if (!visit[nxt[0]][nxt[2]]) {
				visit[nxt[0]][nxt[2]] = 1;
				q.push(nxt);
			}
		}

	}
	cout << 0;
	return 0;

}