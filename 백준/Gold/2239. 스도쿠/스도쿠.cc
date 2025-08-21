#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int board[10][10];
int zero;
vector<pair<int, int>> v;
bool row[9][10]; // i행의 j(1~9)가 이미 있는지
bool col[9][10]; // i열의 j(1~9)가 이미 있는지
bool box[9][10]; // i번째 box의 j(1~9)가 이미 있는지->i번째 box는 sx/3*3 + sy
void dfs(int idx)
{
    if (idx == zero)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j];
            }
            cout << "\n";
        }
        exit(0); // 가장 첫번째 도달하면 종료
        return;
    }
    int x = v[idx].first;
    int y = v[idx].second;
    for (int i = 1; i <= 9; i++)
    {
        board[x][y] = i;
        // x, y에 i를 넣었을 때 스도쿠가 되는지 검사
        int sx = x / 3 * 3;
        int sy = y / 3 * 3;
        int z = sx + sy / 3; // box의 번호
        if (!row[x][i] && !col[y][i] && !box[z][i])
        {
            row[x][i] = 1;
            col[y][i] = 1;
            box[z][i] = 1;
            dfs(idx + 1);
            row[x][i] = 0;
            col[y][i] = 0;
            box[z][i] = 0;
        }
        board[x][y] = 0;
    }
}
int main()
{

    for (int i = 0; i < 9; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = s[j] - '0';
            int num = board[i][j];
            if (!board[i][j])
            {
                zero++;
                v.push_back({i, j});
            }
            else
            {
                row[i][num] = 1;
                col[j][num] = 1;
                int sx = i / 3 * 3;
                int sy = j / 3 * 3;
                int k = sx + sy / 3; // box의 번호
                box[k][num] = 1;
            }
        }
    }
    dfs(0);
}