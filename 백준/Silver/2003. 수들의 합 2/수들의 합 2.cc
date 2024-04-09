#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <math.h>
#include <string.h>
#include <tuple>
#include <queue>
using namespace std;
int n, m;
int ans = 0;
int sum = 0;
int arr[10002];
int st, en = 0;
int main() {
	//m이 되는 경우의 수
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sum = 0;
	while (en <= n) {

		if (sum == m) {
			//모든 경우의 수 찾아야 하기 때문에 부분합 발견해도 앞으로 계속 탐색
			ans++;
			sum -= arr[st];
			st++;
		}
		else if (sum < m) {
			//en++하고 sum에 v[en]더함
			sum += arr[en];
			en++;
		}
		else {
			//sum에서 v[st]빼고 st++
			sum -= arr[st];
			st++;
		}
	}
	cout << ans;
}