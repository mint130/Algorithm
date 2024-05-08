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
bool ans[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int answer = 0;
	fill(ans, ans + 1001, true);
	for (int i = 123; i <= 987; i++) {
		string temp = to_string(i);
		//중복 숫자 포함이거나
		if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2]) ans[i] = false;
		//0이 포함되면 false
		if (temp[0] - '0' == 0 || temp[1] - '0' == 0 || temp[2] - '0' == 0) ans[i] = false;
	}

	for (int i = 0; i < n; i++) {
		//세자리 수, 답한 스트라이크 개수, 볼의 갯수
		int num, strike, ball;
		cin >> num >> strike >> ball;
		string n_str = to_string(num); //str[0], str[1], str[2]

		//입력받은 숫자 n을 123~987까지 비교하며 strike와 ball의 갯수를 셈
		for (int j = 123; j <= 987; j++) {
			int s = 0;
			int b = 0;
			string temp = to_string(j);
			if (ans[j]) {
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						if (x == y && temp[x]==n_str[y]) {
							//위치도 같고 숫자도 같은 경우
							s++;
						}
						if (x != y && temp[x] == n_str[y]) {
							//위치는 다른데 숫자는 같은 경우
							b++;
						}
					}
				}
			}
			//strike와 ball의 갯수가 현재 j와 비교해서 얻은 s, b의 갯수와 다르면 답이 될 수 없으므로 false
			if (s != strike || b != ball) ans[j] = false;
		}
		
	}
	for (int i = 123; i <= 987; i++) {
		if (ans[i]) answer++;
	}
	cout << answer;
}