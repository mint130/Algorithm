#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
map<string, int> m;
int t;
int parent[200001];
int child[200001];
int findParent(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = findParent(parent[x]);
}
int makeUnion(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a != b)
	{
		if (child[a] <= child[b]) {
			// 친구 더 큰쪽으로 합침
			parent[a] = b;
			child[b] += child[a];
			return child[b];
		}
		else {
			parent[b] = a;
			child[a] += child[b];
			return child[a];
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		m.clear();
		for (int i = 1; i <= 200000; i++) {
			parent[i] = i;
			child[i] = 1;
		}
		int cnt = 0; // 실제 사람
		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (m[s1] == 0) {
				cnt++;
				// 번호 배정
				m[s1] = cnt;
			}
			if (m[s2] == 0) {
				cnt++;
				m[s2] = cnt;
			}
			int num1 = m[s1];
			int num2 = m[s2];
			if (findParent(num1) != findParent(num2)) {
				// 합치고 자식도 합침
				cout << makeUnion(num1, num2) << "\n";
			}
			else {
				cout << child[findParent(num1)] << "\n";
			}
		}
	}
}