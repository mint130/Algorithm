#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
long long s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long sum = 0;
	int i = 1;
	int num = 0;
	cin >> s;
	while (1) {
		sum += i;
		num++;
		if (sum > s) {
			num--;
			break;
		}
		i++;
	}
	cout << num;

}