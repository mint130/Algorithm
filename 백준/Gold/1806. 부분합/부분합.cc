#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

int arr[100000];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int st, en;
	st = 0;
	en = 0;
	int tot = arr[st];
	
	int ans = 987654321;
	//길이는 en-st+1
	while (st < n && en < n) {
		if (st == en && arr[st] >= m) {
			ans = 1;
			break;
		}
		if (tot < m) {
			en++;
			tot += arr[en];
		}
		else {
			ans = min(ans, en - st + 1);
			tot -= arr[st];
			st++;
		}
	}
	
	if (ans == 987654321) ans = 0;
	cout << ans;

}