#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector <int> n;
//vector <int> m;


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
		cout<<binary_search(n.begin(), n.end(), k)<<"\n";
	}

}