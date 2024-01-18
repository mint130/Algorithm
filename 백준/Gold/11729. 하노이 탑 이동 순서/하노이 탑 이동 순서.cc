#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int cnt = 0;
vector<pair<int, int>> v;
void hanoi(int n, int start, int goal, int via) {
	if (n <= 1) {
		cout << start << " " << goal<<"\n"; //n번 원판을 기둥 1에서 기둥 3으로
	}
	else {
		hanoi(n - 1, start, via, goal); //n-1개의 원판을 기둥 1에서 기둥 2로
		cout << start << " " << goal <<"\n"; //n번 원판을 기둥 1에서 기둥 3으로
		hanoi(n - 1, via, goal, start); //n-1개의 원판을 기둥 2에서 기둥 3으로
	}

}

int main() {
	cin >> n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << (1 << n) - 1 << "\n";
	hanoi(n, 1, 3, 2);


	//printHanoi(n, 1, 3, 2);
}