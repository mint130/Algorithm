#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string.h>
#include <cstring>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		//시, 분으로 이루어진 시각입력받아 시, 분 형태로 출력
		vector<int> answer(2);
		int h1, m1;
		int h2, m2;
		cin >> h1 >> m1 >> h2 >> m2;
		
		//분으로 변환
		int min = m1 + h2 * 60 + m2;
		int h = min / 60; //더해야 하는 시
		int m = min % 60; //남은 분
		if (h1 + h > 12) answer[0] = h1 + h - 12;
		else answer[0] = h1 + h;
		answer[1] = m;
		cout << "#" << tc << " " << answer[0] << " " << answer[1] << "\n";
	}
	
}