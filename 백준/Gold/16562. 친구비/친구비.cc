#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
int arr[10001]; // 친구비
int parent[10001];
int findParent(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = findParent(parent[x]);
}
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a != b) {
		if (arr[a] < arr[b]) {
			// a의 친구비용이 더 작다
			// b의 부모를 a로 만듦
			parent[b] = a;
		}
		else {
			parent[a] = b;
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <=n; i++) {
		parent[i] = i;
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i == parent[i]) {
			// 집단 내에서 제일 친구비가 작은 사람
			ans += arr[i];
		}
	}
	if (ans > k) cout << "Oh no";
	else cout << ans;

}