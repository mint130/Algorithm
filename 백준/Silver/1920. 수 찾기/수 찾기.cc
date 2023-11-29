#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector <int> n;
//vector <int> m;


bool binary_search(vector<int>& arr, int low, int high, int target) {
	
	if (low > high) return false;
	int mid = (high + low) / 2;
	if (arr[mid] == target) return true;
	if (arr[mid] < target) // high = mid - 1;
		return binary_search(arr, mid + 1, high, target); 
	else //arr[mid]>target
		return binary_search(arr, low, mid - 1, target);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		n.push_back(k);
	}
	sort(n.begin(), n.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		int k;
		cin >> k;
		cout<<binary_search(n, 0, N-1, k)<<"\n";
	}

}