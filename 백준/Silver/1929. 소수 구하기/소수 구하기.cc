#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	vector<bool> state(n + 1, true);
	state[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (!state[i]) continue;
		for (int j = i * i; j <= n; j += i) {
			state[j] = false; //소수가 아님
		}
	}
	for (int i = m; i < state.size(); i++) {
		if (state[i]) {
			cout << i << "\n";
		}
	}
}