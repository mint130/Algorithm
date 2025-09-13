#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
int n, m;
int arr[101][101];   // 부순 벽의 갯수
int board[101][101]; // 0은 빈 방, 1은 벽
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
using namespace std;
int main()
{
    cin >> m >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = s[j] - '0';
            arr[i][j] = 987654321;
        }
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    arr[0][0] = 0;
    pq.push({0, {0, 0}});
    while (!pq.empty())
    {
        int change = pq.top().first; // 바뀐 벽의 갯수
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();
        if (x == n - 1 && y == m - 1)
        {
            cout << arr[x][y];
            return 0;
        }
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (arr[nx][ny] > arr[x][y] + board[nx][ny])
            {
                // 벽이면 +1
                arr[nx][ny] = arr[x][y] + board[nx][ny];
                pq.push({arr[nx][ny], {nx, ny}});
            }
        }
    }
}