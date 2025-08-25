#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
char board[11][11];
int dist[11][11][11][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct node
{
    // 빨간 파란 공 좌표, 횟수
    int rx, ry, bx, by, cnt;
};
int move(int &x, int &y, int d)
{
    int distance = 0;
    while (board[x + dx[d]][y + dy[d]] != '#' && board[x][y] != 'O')
    {
        x += dx[d];
        y += dy[d];
        distance++;
        if (board[x][y] == 'O')
            break;
    }
    return distance;
}

int main()
{
    cin >> n >> m;
    queue<node> q;
    int rx, ry, bx, by;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                rx = i;
                ry = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B')
            {
                bx = i;
                by = j;
                board[i][j] = '.';
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    q.push({rx, ry, bx, by, 0});
    dist[rx][ry][bx][by] = 0;

    while (!q.empty())
    {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int cnt = q.front().cnt;
        q.pop();
        if (cnt >= 10)
        {
            cout << -1;
            return 0;
        }
        for (int d = 0; d < 4; d++)
        {
            int nrx = rx;
            int nry = ry;
            int nbx = bx;
            int nby = by;
            int rmove = move(nrx, nry, d);
            int bmove = move(nbx, nby, d);
            if (board[nbx][nby] == 'O')
                continue; // 파란게 들어감
            if (board[nrx][nry] == 'O')
            {
                // 빨간것만 도착점에 도달
                cout << cnt + 1;
                return 0;
            }

            if (nrx == nbx && nry == nby)
            {
                // 둘이 겹침 -> 더 많이 이동한 것을 하나 뒤로 빼줌
                if (rmove > bmove)
                {
                    // 빨간게 더 많이 움직임
                    nrx -= dx[d];
                    nry -= dy[d];
                }
                else
                {
                    nbx -= dx[d];
                    nby -= dy[d];
                }
            }
            // 방문 처리
            if (dist[nrx][nry][nbx][nby] == -1)
            {
                dist[nrx][nry][nbx][nby] = cnt + 1;
                q.push({nrx, nry, nbx, nby, cnt + 1});
            }
        }
    }
    cout << -1;
}