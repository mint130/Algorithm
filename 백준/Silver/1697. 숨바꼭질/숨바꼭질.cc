#include <iostream>
#include <queue>

using namespace std;

int N, K; //N은 수빈이 위치, K는 동생 위치
int dist[100002] = { -1, };
queue<int> q;
void bfs() {

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (dist[K]!=-1)
		{
			cout << dist[K];
			break;
		}
		if (x+1<=100000 && dist[x + 1] < 0)
		{
			dist[x + 1] = dist[x] + 1;
			q.push(x + 1);
		}
		if (x-1<=100000 && dist[x - 1] < 0)
		{
			dist[x - 1] = dist[x] + 1;
			q.push(x - 1);
		}
		if (x*2<=100000 && dist[2 * x] < 0)
		{
			dist[2 * x] = dist[x] + 1;
			q.push(2 * x);
		}
	}

}
int main() {

	fill(dist, dist + 100002, -1);
	cin >> N >> K;
	q.push(N);
	dist[N] = 0;
	bfs();
	
}