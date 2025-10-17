#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
using namespace std;
int n, k, l;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 아래, 오른쪽, 위, 왼쪽
int board[101][101];
bool snake[101][101];
int dir[10001];          // -1은 왼쪽, +1은 오른쪽
deque<pair<int, int>> q; // front가 머리, back이 꼬리

int main()
{
    cin >> n >> k;
    snake[0][0] = 1;
    q.push_back({0, 0});
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = 1; // 사과
    }
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        if (c == 'L')
            dir[x] = -1;
        else
            dir[x] = 1;
    }
    int t = 0;
    int cur = 1; // 현재 방향
    while (1)
    {
        t++;
        int x = q.front().first;
        int y = q.front().second;

        // 현재 머리
        int nx = x + dx[cur];
        int ny = y + dy[cur];

        // 머리가 벽에 닿았거나 자기 자신과 닿음
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            break;
        if (snake[nx][ny])
            break;

        if (board[nx][ny])
        {
            // 사과 있음
            snake[nx][ny] = 1; // 머리 위치
            board[nx][ny] = 0; // 사과 없앰
            q.push_front({nx, ny});
        }
        else
        {
            // 사과 없음
            q.push_front({nx, ny}); // 머리 넣음
            snake[nx][ny] = 1;
            // 꼬리 없앰
            int tx = q.back().first;
            int ty = q.back().second;
            snake[tx][ty] = 0;
            q.pop_back();
        }

        // 방향 전환이 필요한지
        if (dir[t] == 1)
        {
            // 오른쪽
            // 0일때 3, 1일때 0, 2일때 1, 3일때 2
            cur = (cur + 3) % 4;
        }
        else if (dir[t] == -1)
        {
            // 왼쪽
            // 0일때 1, 1일때 2, 2일때 3, 3일때 0
            cur = (cur + 1) % 4;
        }
    }

    cout << t;
}