#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <tuple>
using namespace std;

int v, e;
int parent[10002];
tuple<int, int, int> edge[100002];
//cost, a, b
int ans = 0; //최소 스패닝 트리의 가중치
int cnt = 0; //최소 스패닝 트리의 간선 수
//부모를 찾는 find 함수
int find_parent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find_parent(parent[x]);

}
//서로 같은 부모를 갖는 지 확인
bool same_parent(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);
	if (x==y) return true;
	else return false;

}

//서로 다른 부모일 경우 두개의 노드 연결
void union_node(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);
	if (x != y) parent[y] = x;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		edge[i] = { cost, a, b };
		
	}
	sort(edge, edge + e); //가중치 순으로 정렬
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < e; i++) {
		int cost, a, b;
		tie(cost, a, b) = edge[i];
		//a, b의 parent가 다르면 노드 합치고 최소 스패닝 트리에 cost 추가
		if (!same_parent(a, b)) {
			union_node(a, b);
			ans += cost;
			cnt++;
		}
		if (cnt == v - 1) break;
	}
	cout << ans;
}