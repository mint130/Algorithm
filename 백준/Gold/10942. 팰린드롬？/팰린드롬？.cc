#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[2002];
bool dp[2002][2002];
int n, m;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
        if (i + 1 <= n)
        {
            if (arr[i] == arr[i + 1])
            {
                dp[i][i + 1] = 1;
            }
        }
    }
    for (int i = n - 2; i >= 1; i--)
    {
        for (int j = i + 2; j <= n; j++)
        {
            // dp[i+1][j-1]이 팰린드롬이면서 arr[i]==arr[j]이면 팰린드롬
            if (dp[i + 1][j - 1] && arr[i] == arr[j])
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << "\n";
    }
}