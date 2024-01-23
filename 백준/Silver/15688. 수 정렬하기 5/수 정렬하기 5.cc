#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[1000002];
int tmp[1000002];
void merge(int st, int en) {
	int mid = (st + en) / 2;

	int idx_l = st;
	int idx_r = mid;
	int idx_t = st;

	while (idx_l < mid && idx_r < en) {
		if (arr[idx_l] < arr[idx_r]) {
			tmp[idx_t] = arr[idx_l];
			idx_l++;
			idx_t++;
		}
		else if (arr[idx_l] >= arr[idx_r]) {
			tmp[idx_t] = arr[idx_r];
			idx_r++;
			idx_t++;
		}
	}
	while (idx_l < mid) {
		tmp[idx_t] = arr[idx_l];
		idx_t++;
		idx_l++;
	}
	while (idx_r < en) {
		tmp[idx_t] = arr[idx_r];
		idx_t++;
		idx_r++;
	}
	for (int i = st; i < en; i++) {
		arr[i] = tmp[i];
	}
}
//priority_queue<int, vector<int>, greater<int>> pq;
void merge_sort(int st, int en) {
	if (en == st + 1) {
		return;
	}
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	/*for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}
	while (!pq.empty()) {
		cout<<pq.top()<<"\n";
		pq.pop();
	}*/
	merge_sort(0, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
}