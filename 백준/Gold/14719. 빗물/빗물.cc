#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
using namespace std;
int h, w, ans;
int arr[502];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w;
	//세로 가로
	for (int i = 1; i <= w; i++) {
		cin >> arr[i];
	}
	for (int i = 2; i < w; i++) {
		int l = 0;
		int r = 0;
		int cur = arr[i];
		for (int j = 1; j < i; j++) {
			l = max(l, arr[j]);
		}
		for (int j = i + 1; j <= w; j++) {
			r = max(r, arr[j]);
		}
		if (min(l, r) - cur > 0)ans += min(l, r) - cur;
	}
	cout << ans;
}