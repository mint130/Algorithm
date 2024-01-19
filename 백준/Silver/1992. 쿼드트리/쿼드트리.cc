#include <iostream>

using namespace std;
char video[66][66];
int n;

void quadtree(int x, int y, int size) {

	char first = video[x][y];
	bool check = true; //시작점부터 size까지 x, y 전부 first와 일치하면 true 반환 아니면 분할 정복

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (video[x + i][y + j] != first) {
				check = false;
				break;
			}
		}
	}
	if (check == true) {
		cout << first;
		return;
	}
	else {
		//분할 정복 
		int half = size / 2;

		cout << "(";
		quadtree(x, y, half);
		quadtree(x, y + half, half);
		quadtree(x + half, y, half);
		quadtree(x + half, y + half, half);
		cout << ")";
	}
}
int main() {

	//분할 정복 문제
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			video[i][j] = s[j];
		}
	}

	quadtree(0, 0, n);
	
}