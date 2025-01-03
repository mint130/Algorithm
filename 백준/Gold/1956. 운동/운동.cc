#include <iostream>
using namespace std;

int v, e;
// 사이클을 찾는다
int dp[401][401];
int ans = 987654321;
int main()
{
    cin >> v >> e;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            dp[i][j] = 987654321;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = c;
    }
    for (int k = 1; k <= v; k++)
    {
        // k는 거쳐가는 값
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            if (k == i)
                continue;
            dp[i][i] = min(dp[i][k] + dp[k][i], dp[i][i]);
            ans = min(dp[i][i], ans);
        }
    }
    if (ans == 987654321)
        ans = -1;
    cout << ans;
}