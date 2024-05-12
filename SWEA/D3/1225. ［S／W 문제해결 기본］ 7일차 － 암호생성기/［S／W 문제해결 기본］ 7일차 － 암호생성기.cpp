#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
int main() {
	int T;
	T = 10;
	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;
		deque<int> dq;
		for (int i = 0; i < 8; i++) {
			int k;
			cin >> k;
			dq.push_back(k);
		}
		while (dq.back()!=0) {
			for (int i = 1; i <= 5; i++)
			{
				int num = dq.front();
				dq.pop_front();
				if (num - i <= 0) {
					dq.push_back(0);
					break;
				}
				dq.push_back(num - i);
			}
		}
		cout << "#" <<tc<<" ";
		while (!dq.empty()) {
			cout << dq.front() << " ";
			dq.pop_front();
		}
		cout << "\n";
		
		
	}

}