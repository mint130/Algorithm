#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int num = 0;
int board[52][52];
int pick[14]; //백트래킹 중 방문했는지
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
int ans= 987654321;

int dist(int chickenx, int chickeny, int homex, int homey) {
	
	return abs(chickenx - homex) + abs(chickeny - homey);
	//거리
}
int distsum() {
	//집을 기준으로 현재 pick된 치킨집 사이의 최단 거리 반환
	
	int distsum = 0;
	for (int i = 0; i < home.size(); i++) {
		int distmin = 987654321;

		int x = home[i].first;
		int y = home[i].second;

		//집의 좌표 -> 집마다 가까운 치킨집은 하나만 존재
		for (int j = 0; j < num; j++) {
			if (pick[j]) {
				//골라진 치킨집
				int cx = chicken[j].first;
				int cy = chicken[j].second;

				distmin = min(distmin, dist(cx, cy, x, y));
				//각 집마다 가장 가까운 치킨집 까지의 거리가 갱신	
			}
		}
		distsum += distmin;
		//집마다 제일 가까운 치킨집의 거리 합 
	}
	return distsum;

}
void dfs(int k, int idx) {
	//num개의 치킨 집 중 k개를 고르는 조합
	
	if (m == k) {
		
		//이 k개의 치킨집 중 치킨 거리가 가장 적은 치킨집 조합을 찾아야 함
		//pick 안에 들어있는 게 현재 골라진 치킨집
		ans= min(distsum(), ans);
		return;

	}
	for (int i = idx; i < chicken.size(); i++) {
		
		if (!pick[i]) {
			pick[i] = 1;
			dfs(k + 1, i);
			pick[i] = 0;
		}
		
	}
}
int main() {

	//최대 m개 고른다 -> 백트래킹?
	//집에서 가장 가까운 치킨집 찾기 -> 1에서 가장 가까운 2 찾아야 함
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				home.push_back({ i, j }); 
				
			}
			else if (board[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}
	//num은 현재 치킨집의 수
	num = chicken.size();
	dfs(0, 0); //num개 중 k개의 치킨집을 구함
	//집마다 가장 가까운 치킨 거리를 구해야 함
	cout << ans;
}