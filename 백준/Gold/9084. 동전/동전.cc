#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
int t, n, m;
int coin[21];
int dp[21][10001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        fill(coin, coin + n + 1, 0);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            cin >> coin[i];
        }
        cin >> m;
        dp[0][0] = 1; // 동전 0개써서 0 만드는 경우의 수 1
        for (int i = 1; i <= n; i++)
        {

            for (int j = 0; j <= m; j++)
            {
                // 합이 j가 되려면
                dp[i][j] = dp[i - 1][j];
                if (j >= coin[i])
                {
                    dp[i][j] += dp[i][j - coin[i]];
                }
            }
        }
        cout << dp[n][m] << "\n";
    }
}