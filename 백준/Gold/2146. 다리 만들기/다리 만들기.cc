#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int board[101][101];
int n;
int ans = 98765421;
int cnt = 1;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int island[101][101]; // 섬을 만드는 dist 배열
int road[101][101];   // 도로를 만드는 dist 배열
int out[101][101];    // 외곽 찾는 dist 배열
int dist[101][101];
vector<pair<int, int>> v; // 외곽 넣음
void obfs(int r, int c)
{
    dist[r][c] = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (dist[nx][ny] != -1)
                continue;
            if (board[nx][ny] == 0)
            {
                // 바다
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
            if (board[nx][ny] != 0)
            {
                // 섬의 외곽
                out[nx][ny] = 1;
                v.push_back({nx, ny});
            }
        }
    }
}
void ibfs(int r, int c)
{
    island[r][c] = 0;
    board[r][c] = cnt;
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (board[nx][ny] == 0 || island[nx][ny] != -1)
                continue;
            island[nx][ny] = island[x][y] + 1;
            board[nx][ny] = cnt;
            q.push({nx, ny});
        }
    }
}
void vbfs(int r, int c, int num)
{
    road[r][c] = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (board[x][y] != 0 && board[x][y] != num)
        {
            // 바다가 아니고 자기와 다른 섬에 닿음
            ans = min(ans, road[x][y]);
            break;
        }
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (road[nx][ny] != -1)
                continue;
            if (board[nx][ny] == 0 || board[nx][ny] != num)
            {
                q.push({nx, ny});
                road[nx][ny] = road[x][y] + 1;
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            island[i][j] = -1;
            road[i][j] = -1;
            dist[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] && island[i][j] == -1)
            {
                // 섬 만드는 bfs
                ibfs(i, j);
                cnt++;
            }
            if (board[i][j] == 0 && dist[i][j] == -1)
            {
                // 외곽 찾는 bfs
                obfs(i, j);
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        vbfs(x, y, board[x][y]);
        memset(road, -1, sizeof(road));
    }

    cout << ans - 1;
}