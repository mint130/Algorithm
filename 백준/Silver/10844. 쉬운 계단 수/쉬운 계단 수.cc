#include <iostream>
#include <algorithm>
using namespace std;
int N;
long long dp[101][10]; // 길이가 n, 끝이 m인 계단수의 갯수

int main()
{
    cin >> N;
    // 길이가 n인 계단수
    for (int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
                dp[i][0] = (dp[i - 1][1]) % 1000000000; // 1이거나 8인 경우에만 0이나 9가 됨
            else if (j == 9)
                dp[i][9] = (dp[i - 1][8]) % 1000000000;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }
    long long ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans += dp[N][i];
    }
    cout << ans % 1000000000;
}