#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

//queue<int> q;
priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;	//가장 빠른 시간과 현재 위치를 같이 넣어야 함

int arr[100002];
int n, k;

int main() {

	cin >> n >> k;
	//n은 수빈이의 위치, k는 동생의 위치
	
	fill(arr, arr + 100002, -1);
	//arr배열을 -1로 채움
	arr[n] = 0;
	pq.push({ 0, n }); //걸린 시간과 현재 위치

	while (!pq.empty()) {
		
		int time = pq.top().first;
		int x = pq.top().second;

		//cout << time << " " << x << endl;

		pq.pop();

		if (x == k)
		{
			cout << time;
			return 0;
		}

		if (2 * x <= 100000 && arr[2 * x] == -1)
		{
			arr[2 * x] = arr[x];
			pq.push({ time , 2 * x });
		}
		if (x + 1 <= 100000 && arr[x + 1] == -1)
		{
			arr[x + 1] = arr[x] + 1;
			pq.push({ time + 1 , x + 1 });
		}
		if (x - 1 <= 100000 && arr[x - 1] == -1) {
			arr[x - 1] = arr[x] + 1;
			pq.push({ time + 1 , x - 1 });
		}
		
	}
}