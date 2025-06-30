#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int board[10][10];
bool flag;
vector<pair<int, int>> v;
bool check(int x, int y, int num)
{

    // 행 체크
    for (int i = 0; i < 9; i++)
    {
        if (board[i][y] == num)
            return false;
    }
    // 열 체크
    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == num)
            return false;
    }
    // 박스 체크
    // 세로로 몇번째 박스인지
    int r = (x / 3) * 3;
    // 가로로 몇번째 박스인지
    int c = (y / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[r + i][c + j] == num)
                return false;
        }
    }
    return true;
}

void dfs(int cur)
{
    if (flag)
        return;
    if (cur == v.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
            flag = 1;
        }
    }

    int x = v[cur].first;
    int y = v[cur].second;
    for (int i = 1; i <= 9; i++)
    {
        // i를 넣을 수 있는지 확인
        if (!check(x, y, i))
            continue;
        board[x][y] = i;
        dfs(cur + 1);
        board[x][y] = 0;
    }
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                v.push_back({i, j});
        }
    }
    dfs(0);
}