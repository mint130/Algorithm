#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int board[2223][2223];
int dp[2223][2223]; // board[i][j]까지 왔을 때 최소비용
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            dp[i][j] = 987654321;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int cur = board[i][j];
            int left = 0;
            int top = 0;

            if (j != 0)
                left = board[i][j - 1]; // 왼쪽
            if (i != 0)
                top = board[i - 1][j]; // 위쪽

            if (i != 0)
            {
                if (top <= cur)
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + cur - top + 1);
                }
                else
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
            if (j != 0)
            {
                if (left <= cur)
                {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + cur - left + 1);
                }
                else
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n - 1][n - 1];
}