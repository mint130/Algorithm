#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int board[21][21];
int ans = 987654321;
bool used[21];
void calc()
{
    vector<int> start;
    vector<int> link;
    for (int i = 1; i <= N; i++)
    {
        if (used[i])
            start.push_back(i);
        else
            link.push_back(i);
    }
    int s = 0;
    int l = 0;
    for (int i = 0; i < start.size(); i++)
    {
        for (int j = 0; j < start.size(); j++)
        {
            if (i == j)
                continue;
            s += board[start[i]][start[j]];
        }
    }
    for (int i = 0; i < link.size(); i++)
    {
        for (int j = 0; j < link.size(); j++)
        {
            if (i == j)
                continue;
            l += board[link[i]][link[j]];
        }
    }
    ans = min(ans, abs(s - l));
}
void dfs(int idx, int cnt)
{
    if (cnt == N / 2)
    {
        calc();
        return;
    }
    for (int i = idx; i <= N; i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            dfs(i + 1, cnt + 1);
            used[i] = 0;
        }
    }
}
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
        }
    }
    dfs(0, 0);
    cout << ans;
}