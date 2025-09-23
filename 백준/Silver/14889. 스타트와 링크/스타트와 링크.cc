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
        vector<int> st;
        vector<int> lk;
        for (int i = 0; i < n; i++)
        {
            if (isUsed[i])
                st.push_back(i);
            else
                lk.push_back(i);
        }
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                sum1 += board[st[i]][st[j]];
                sum2 += board[lk[i]][lk[j]];
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