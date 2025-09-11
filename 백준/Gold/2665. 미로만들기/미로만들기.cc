#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, board[51][51];
queue<pair<int, int>> q;
int cnt[51][51]; // 바꾼 방 갯수
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            board[i][j] = s[j] - '0';
            cnt[i][j] = 987654321;
        }
    }
    // 1은 흰방, 0은 검은방
    cnt[0][0] = 0;
    q.push({0, 0});
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
            if (board[nx][ny])
            {
                // 흰 방
                // 뚫고 온 방 갯수가 더 많으면 적게 바꿔줌
                if (cnt[nx][ny] > cnt[x][y])
                {
                    cnt[nx][ny] = cnt[x][y];
                    q.push({nx, ny});
                }
            }
            else
            {
                // 검은 방
                if (cnt[nx][ny] > cnt[x][y] + 1)
                {
                    cnt[nx][ny] = cnt[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << cnt[n - 1][n - 1];
}
