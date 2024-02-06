#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
int n, m;
int arr[1000002];

vector <int> ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		
		cin >> arr[i];
		ans.push_back(arr[i]);
	
	}
	//정렬
	sort(ans.begin(), ans.end());
	//중복 제거 
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	//자신보다 작은 수 몇개 있는지 세기
	for (int i = 0; i < n; i++) {
		//arr[i]보다 작은 수를 세려면 lowerbound
		int num = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
		//iterator이라 ans.begin() 빼줌
		cout << num << " ";
	}
	

	
}