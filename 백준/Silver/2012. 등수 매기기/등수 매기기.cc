#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int n;
int arr[500002]; //입력받은 숫자
set<int> s;

long long answer = 0;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		s.insert(i + 1);
		int num;
		cin >> arr[i];
	}
	sort(arr, arr + n); //입력받은 숫자 정렬
	for (int i = 0; i < n; i++) {
		int num = arr[i];
		if (s.find(num)!=s.end()) {
			//존재
			s.erase(num);
			arr[i] = 0;

		}
		else {
			answer += abs(arr[i] - *s.begin());
			s.erase(*s.begin());
		}
	}
	cout << answer;


}