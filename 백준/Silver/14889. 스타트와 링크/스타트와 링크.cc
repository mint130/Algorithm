#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int board[22][22];
int n;
int ans = 987654321;
bool isUsed[22];
void dfs(int cnt, int idx)
{
    if (cnt == n / 2)
    {
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isUsed[i] && isUsed[j])
                {
                    sum1 += board[i][j];
                }
                if (!isUsed[i] && !isUsed[j])
                {
                    sum2 += board[i][j];
                }
            }
        }
        ans = min(abs(sum1 - sum2), ans);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (!isUsed[i])
        {
            isUsed[i] = 1;
            dfs(cnt + 1, i + 1);
            isUsed[i] = 0;
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
        }
    }
    dfs(0, 0);
    cout << ans;
}