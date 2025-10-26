#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
bool visited[7];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[101][101];
int dist[101][101];
int cnt = 1;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
void getDist(int island)
{
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (board[x][y] != island)
                continue;

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];
                int len = 0;

                while (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    if (board[nx][ny] == island)
                        break;
                    if (board[nx][ny] > 0 && board[nx][ny] != island)
                    {
                        if (len >= 2)
                        {
                            // 길이가 2부터 pq에 넣음
                            pq.push({len, board[nx][ny]});
                        }
                        break;
                    }
                    if (board[nx][ny] == 0)
                        len++;
                    nx += dx[d];
                    ny += dy[d];
                }
            }
        }
    }
}

void bfs(int i, int j)
{
    dist[i][j] = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    board[i][j] = cnt;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] == -1 && board[nx][ny])
            {
                dist[nx][ny] = dist[x][y] + 1;
                board[nx][ny] = cnt;
                q.push({nx, ny});
            }
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
            dist[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == -1 && board[i][j])
            {
                bfs(i, j);
                cnt++;
            }
        }
    }

    cnt--; // 섬의 실제 갯수
    // 각 섬마다 다른 섬으로 가는 길 중 제일 짧은거 찾아서 더함
    int connected = 0;
    int sum = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int d = pq.top().first;
        int cur = pq.top().second;

        pq.pop();
        if (visited[cur])
            continue;
        visited[cur] = 1;
        sum += d;
        connected++;
        // cur번 섬에서 다른 섬까지의 거리 구해서 넣음
        getDist(cur);
    }
    if (connected == cnt)
        cout << sum;
    else
        cout << -1;
}