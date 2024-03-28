#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n;
	
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			cout << i << '\n';
			n /= i;
		}
	}
	if (n != 1) cout << n;
}