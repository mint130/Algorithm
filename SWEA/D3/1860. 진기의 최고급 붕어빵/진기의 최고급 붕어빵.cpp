#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <set>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n, m, k;
		cin >> n >> m >> k;
		//n은 도착하는 초
		//m은 붕어빵 만드는데 드는 시간
		//k는 만드는 붕어빵 갯수
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		int i = 0; //현재 시간
		int cnt = 0; //붕어빵 갯수
		bool flag = 0;
		int idx = 0; //손님 오는 시간
		string str = " Possible";
		for (int i = 0; i <= v[n - 1]; i++) {
			//마지막 손님이 오는 시간 v[n-1]
			int time = v[idx];
            
			if (i>0 && i % m == 0) {
				cnt += k; 
			}
            
			if (i == time) {
				//손님 도착
				if (cnt <= 0) {
					str = " Impossible";
					break;
				}
                cnt--;
				idx++;
			}
		}
		cout << "#" << tc << str << "\n";
	}
}