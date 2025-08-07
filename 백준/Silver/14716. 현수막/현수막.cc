#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m, ans;
int board[251][251];
bool visited[251][251];
int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int d = 0; d < 8; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visited[nx][ny] || board[nx][ny] == 0)
                continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1 && !visited[i][j])
            {
                bfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
}