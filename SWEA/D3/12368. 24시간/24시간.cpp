#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		//0시부터 0시까지 (24를 0)
		int a, b;
		int answer = 0;
		cin >> a >> b;
		int sum = a + b;
		if (sum == 24) answer = 0;
		else if (sum > 24) answer=sum-24;
		else answer = sum;
		cout << "#" << tc << " " << answer << "\n";
	}
}