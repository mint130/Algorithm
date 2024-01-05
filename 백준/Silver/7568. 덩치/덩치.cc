#include <iostream>
#include <algorithm>

#include <vector>
using namespace std;

vector <pair<int, int>> v;


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int h, w;
		cin >> h >> w;
		v.push_back({ h, w });
	}
	int rank = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i].first < v[j].first && v[i].second < v[j].second) {
				rank++;
			}
			
		}
		cout << rank << " ";
		rank = 1;
	}
}