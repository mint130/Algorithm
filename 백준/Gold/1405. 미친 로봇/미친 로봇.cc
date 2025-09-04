#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
int n;
int arr[4]; // E W S N
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[29][29];
double ans = 0;
void dfs(int x, int y, int cnt, double percent) {
	if (cnt == n) {
		ans += percent;
		return;
	}
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (visited[nx][ny]) continue;
		visited[nx][ny] = 1;
		dfs(nx, ny, cnt + 1, percent * ((double)(arr[d]/100.0)));
		visited[nx][ny] = 0;
	}

}
int main() {
	cin >> n;
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}
	visited[14][14] = 1;
	dfs(14, 14, 0, 1.0);
	cout.precision(10);
	cout << ans;
}