#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
bool isPerfect(int n) {
	v.erase(v.begin(), v.end());
	int sum = 0;
	int i = 1; //약수 구하기
	while (i <= n-1) {
		if (n % i == 0) v.push_back(i);
		i++;
	}
	for (int j = 0; j < v.size(); j++) {
		sum += v[j];
	}
	if (sum == n) return true;
	else return false;
	
}
int main() {
	int n=0;
	while (n != -1) {
		cin >> n;
		if (n == -1) return 0;
		if (isPerfect(n)) {
			cout << n << " = ";
			for (int i = 0; i < v.size(); i++) {
				if(i!=v.size()-1){
					cout << v[i] << " + ";
				}
				else {
					cout << v[i] << "\n";
				}
			}
			
		}
		else {
			cout << n << " is NOT perfect." << "\n";
		}
	}
}