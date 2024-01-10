#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int tc;
	cin >> tc;
	//함수 r은 배열에 있는 수의 순서를 뒤집는다
	//함수 d는 첫번째 수를 버린다, 배열이 비었는데 d 사용할 수 없다
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < tc; i++) {
		deque<int> dq;
		string p;
		int n;
		int flag = 0;
		string arr;
		cin >> p; //함수
		cin >> n; //숫자 갯수
		cin >> arr; //숫자가 들어있는 배열

		string temp;
		for (int j = 0; j < arr.length(); j++) {
			if (isdigit(arr[j])) temp+=arr[j];
			else {
				if (temp != "") dq.push_back(stoi(temp));
				temp = "";
			}
		}
		//dq에 수열 넣음

		int isReverse = 0; //0이면 앞에서부터 지우고 앞에서부터 출력 1이면 뒤에서부터 지우고 뒤에서부터 출력

		for (int j = 0; j < p.length(); j++) {
			//함수 갯수만큼 실행
			if (p[j] == 'R') {
				if (isReverse == 1) isReverse = 0;
				else isReverse = 1;
			}
			else {
				if (dq.empty()) {
					//cout << "error\n";
					flag = 1;
					break;
				}
				else {
					if (isReverse == 0) dq.pop_front();
					else dq.pop_back();
				}
			}
		}

		//출력	
		if (flag == 1) cout << "error\n";
		else {
			cout << "[";
			if (isReverse == 0) { //isReverse가 0이면 앞에서부터 출력
				for (int j = 0; j < dq.size(); j++) {
					cout << dq[j];
					if (j != dq.size() - 1) {
						cout << ",";
					}
				}
			}
			else {	//1이면 뒤에서부터 출력
				for (int j = dq.size() - 1; j >= 0;j--) {
					cout << dq[j];
					if (j != 0) {
						cout << ",";
					}
				}	
			}
			cout << "]\n";
		}
	}
}
