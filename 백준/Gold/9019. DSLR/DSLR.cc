#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <set>
using namespace std;
string dist[10000];	//명령어 저장
int distnum[10000];
int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--) {
		fill(dist, dist + 10000, ""); //초기화
		fill(distnum, distnum + 10000, -1);
		int st, en;
		cin >> st >> en;

		queue<int> q;
		q.push(st);
		distnum[st] = 0;
		dist[st] = "";
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur == en) {
				//명령어 출력
				cout << dist[en] << "\n";
				break;
			}
			//n*2배
			int nxt1 = cur * 2;
			if (nxt1 > 9999) nxt1 %= 10000;
			if (distnum[nxt1] == -1) {
				dist[nxt1] = dist[cur] + "D";
				distnum[nxt1] = distnum[cur] + 1;
				q.push(nxt1);
			}
			//n-1
			int nxt2 = cur - 1;
			if (nxt2 < 0) nxt2 = 9999;
			if (distnum[nxt2] == -1) {
				dist[nxt2] = dist[cur] + "S";
				distnum[nxt2] = distnum[cur] + 1;
				q.push(nxt2);
			}
			//왼쪽
			int nxt3 = cur * 10 + cur / 1000;
			if (nxt3 >= 10000) nxt3 %= 10000;
			if (distnum[nxt3] == -1) {
				dist[nxt3] = dist[cur] + "L";
				distnum[nxt3] = distnum[cur] + 1;
				q.push(nxt3);
			}
			//오른쪽
			int nxt4 = cur % 10 * 1000 + cur / 10;
			if (distnum[nxt4] == -1) {
				dist[nxt4] = dist[cur] + "R";
				distnum[nxt4] = distnum[cur] + 1;
				q.push(nxt4);
			}
		}
	}
}