#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0}; // 오른쪽, 위쪽, 왼쪽, 아래쪽
int board[101][101];
vector<pair<int, int>> ans;
int n;
int main()
{
    cin >> n;
    while (n--)
    {
        int x, y, d, g;
        cin >> y >> x >> d >> g;
        vector<int> dir;
        dir.push_back(d);
        for (int i = 0; i < g; i++)
        {
            // 세대별
            int size = dir.size();
            for (int j = size - 1; j >= 0; j--)
            {
                dir.push_back((dir[j] + 1) % 4); // 시계방향 회전
            }
        }
        board[x][y] = 1;
        for (int d : dir)
        {
            x += dx[d];
            y += dy[d];
            if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
                board[x][y] = 1;
        }
    }
    int ans = 0;
    // 정사각형 갯수 세기
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
                ans++;
        }
    }
    cout << ans;
}