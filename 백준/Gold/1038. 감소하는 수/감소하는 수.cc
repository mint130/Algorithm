#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> v;
int n;
bool isused[10];
void dfs(long long num) {
	v.push_back(num);
	if (num % 10 == 0) {
		//마지막이 0이면 return
		return;
	}
	int k = num % 10;
	for (int i = 0; i < k; i++) {
		if (!isused[i]) {
			isused[i] = 1;
			dfs(num * 10 + i);
			isused[i] = 0;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < 10; i++) {
		//시작이 i인 감소하는 수
		dfs(i);
	}
	sort(v.begin(), v.end());
	if (n >= v.size()) cout << -1;
	else cout << v[n];
}