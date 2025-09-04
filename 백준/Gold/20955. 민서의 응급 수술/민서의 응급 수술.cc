#include <iostream>
using namespace std;
int n, m;
int parent[100001];
int findParent(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = findParent(parent[x]);
}
void makeUnion(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (findParent(a) == findParent(b)) {
			ans++;
		}
		else makeUnion(a, b);
	}
	for (int i = 1; i <= n; i++) {
		if (i == findParent(i)) ans++;
	}
	cout << ans - 1; // 집합의 수 -1
}