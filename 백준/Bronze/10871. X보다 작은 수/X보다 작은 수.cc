#include <iostream>
#include <vector>
using namespace std;
int main() {

	int n, x;
	cin >> n >> x;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		if (data < x) v.push_back(data);
	}
	for (int i = 0; i < v.size(); i++){
		cout<<v[i]<<" ";
	}
}