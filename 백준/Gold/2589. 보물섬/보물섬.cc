#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int n, m;
int board[51][51]; // 육지(L)은 1, 바다(W)은 0
int ans = 0;
int dist[51 * 51][51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> v; // 육지 리스트

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == 'W')
                board[i][j] = 0;
            else
            {
                board[i][j] = 1;
                v.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        int r = v[i].first;
        int c = v[i].second;
        memset(dist[i], -1, sizeof(dist[i]));
        dist[i][r][c] = 0;
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
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (board[nx][ny] == 0 || dist[i][nx][ny] != -1)
                    continue;
                q.push({nx, ny});
                dist[i][nx][ny] = dist[i][x][y] + 1;
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                ans = max(dist[i][j][k], ans);
            }
        }
    }
    cout << ans;
}