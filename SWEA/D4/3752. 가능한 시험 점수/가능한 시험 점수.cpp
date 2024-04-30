#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <string.h>
#include <cstring>

using namespace std;


int arr[101];
int n;
int visited[10001]; //합이 될 수 있는 값들
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		vector<int> ans; //합 저장
		ans.push_back(0);
		
		for (int i = 0; i < n; i++) {
			int size = ans.size();
			for (int k = 0; k < size; k++) {
				int sum = arr[i] + ans[k];
				if (!visited[sum]) {
					visited[sum] = 1;
					ans.push_back(sum);
				}
			}
		}
		
		cout << "#" << tc << " " << ans.size() << "\n";
		
	}

}