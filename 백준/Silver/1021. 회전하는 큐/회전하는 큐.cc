#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int idx = 0; //삭제할 원소가 있는 인덱스
	int arr[52];
	int n, m;
	cin >> n >> m;
	deque<int> dq;
	int ans = 0;

	for (int i = 1; i <=n; i++) {
		dq.push_back(i );
	}
	//1부터 n개의 원소가 들어간 dq
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < dq.size(); j++) {
			if (dq[j] == num) { 
				idx = j; 
				break; 
			}
		}
		int mid = dq.size() / 2;
		if (idx <= mid) {
			//2번 연산이 빠르다
			while (1) {
				if (dq.front() == num)
				{
					dq.pop_front();
					break;
				}
				dq.push_back(dq.front());
				dq.pop_front();
				ans++;
			}
		}
		else {
			//3번 연산이 빠르다
			while (1) {
				if (dq.front() == num)
				{
					dq.pop_front();
					break;
				}
				dq.push_front(dq.back());
				dq.pop_back();
				ans++;
			}

		}
		
	
	}


	cout << ans;
}