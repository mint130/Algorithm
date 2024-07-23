#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int h, w, x, y;
int b[602][602];
int a[302][302];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w >> x >> y;
	for (int i = 0; i < h + x; i++) {
		for (int j = 0; j < w + y; j++) {
			cin >> b[i][j];
		}
	}
	//실제는 h, w 
	/*
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < y; j++) {
			a[i][j] = b[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = y; j < w + y; j++) {
			if (i >= x) {
				a[i][j] = b[i][j] - a[i - x][j - y];
			}
			else a[i][j] = b[i][j];
		}
	}*/

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < y + w; j++) {
			if (j < y) {
				a[i][j] = b[i][j];
			}
			else {
				if (i >= x) {
					a[i][j] = b[i][j] - a[i - x][j - y];

				}
				else {
					a[i][j] = b[i][j];
				}
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}