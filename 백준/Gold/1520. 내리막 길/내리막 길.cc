#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int board[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[501][501];
void dfs(int x, int y)
{
    if (x == n - 1 && y == m - 1)
    {
        dp[x][y] = 1;
        return;
    }
    if (dp[x][y] != -1)
        return;

    dp[x][y] = 0;

    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (board[nx][ny] >= board[x][y])
            continue; // 내리막길이 아님
        dfs(nx, ny);
        dp[x][y] += dp[nx][ny];
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
            dp[i][j] = -1;
        }
    }

    dfs(0, 0);
    cout << dp[0][0];
}