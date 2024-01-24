#include <iostream>
#include <queue>

using namespace std;
int arr[102][102];
int kevin[102];
int cnt[102] = { 0, };
int visit[102] = { 0, };
int N, M;

int BFS(int n) {

	int sum = 0; //내부 cnt를 합친 것
	queue<int> q;
	
	q.push(n);
	visit[n] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		//cout << x << endl;
		for (int i = 1; i <= N; i++) {
			
			if (arr[x][i] == 1 && visit[i] == 0) {
				
				cnt[i] = cnt[x] + 1;
				visit[i] = 1;
				q.push(i);
				
			}
		}

	}
	//내부의 cnt들을 합친 것이 케빈 베이컨 수
	for (int i = 1; i <= N; i++) {
		sum += cnt[i];
	}
	return sum;
	
}
int main() {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {

		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;

	}
	int min = 9999999;
	int minIdx = 102;
	for (int i = 1; i <= N; i++) {
		kevin[i] = BFS(i);
		fill(visit, visit + 102, 0);
		fill(cnt, cnt + 102, 0);
	}
	for (int i = 1; i <= N; i++) {
		
		if (kevin[i] == min) continue;
		if (kevin[i] < min) {
			min = kevin[i];
			minIdx = i;
		}
		
	}
	cout << minIdx;
}