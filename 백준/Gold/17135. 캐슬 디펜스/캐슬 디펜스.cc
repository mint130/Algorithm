#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int board[17][16];
int dist[17][16];
int nboard[17][16]; // 매번 움직일 보드
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool ar[16];
int n, m, d;
int a, b, c;
int ans = 0;
int kill = 0;
void attack()
{

    vector<pair<int, int>> enemy; // 죽일 후보
    int archer[3] = {a, b, c};
    // 각 궁수마다 가장 가깝고 왼쪽에 있는 적 넣음
    for (int t = 0; t < 3; t++)
    {
        int ay = archer[t]; // 궁수 y
        int ax = n;
        int minDist = 987654321;
        int tx = -1, ty = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nboard[i][j])
                {
                    int dist = abs(ax - i) + abs(ay - j);
                    if (dist > d)
                        continue;
                    // 더 가까운 거리거나 왼쪽에 더 가까움
                    if (dist < minDist || (dist == minDist && j < ty))
                    {
                        tx = i;
                        ty = j;
                        minDist = dist;
                    }
                }
            }
        }
        // 각 궁수마다 가장 가까운+왼쪽에 가까운 적
        if (tx != -1)
        {
            // 적이 있었으면 넣음
            enemy.push_back({tx, ty});
        }
    }
    // 중복 제거
    sort(enemy.begin(), enemy.end());
    enemy.erase(unique(enemy.begin(), enemy.end()), enemy.end());
    for (auto e : enemy)
    {
        int x = e.first;
        int y = e.second;
        if (nboard[x][y] == 1)
        {
            // 죽게됨
            nboard[x][y] = 0;
            kill++;
        }
    }
}
void init()
{
    a = 0;
    b = 0;
    c = 0;
    // 보드판 옮김
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            nboard[i][j] = board[i][j];
        }
    }
}
bool check()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nboard[i][j])
                return false;
        }
    }
    // 모든 적이 없어짐
    return true;
}
void dfs(int idx, int cnt)
{
    // 궁수 배치
    if (cnt == 3)
    {
        // 배치 완료
        init();
        kill = 0;
        for (int i = 0; i < m; i++)
        {
            if (ar[i] && !a)
                a = i;
            else if (ar[i] && !b)
                b = i;
            else if (ar[i] && !c)
                c = i;
        }
        // 적이 다 없어질 때까지
        while (1)
        {
            // 적이 다 없어졌는지 체크
            if (check())
                break;
            attack(); // 가장 가까이에 있는 적 죽임
            for (int i = n - 1; i >= 1; i--)
            {
                for (int j = 0; j < m; j++)
                {
                    nboard[i][j] = nboard[i - 1][j]; // 한칸 아래로
                }
            }
            for (int j = 0; j < m; j++)
            {
                nboard[0][j] = 0; // 맨 윗줄은 빈칸
            }
        }
        ans = max(ans, kill);
        return;
    }
    for (int i = idx; i < m; i++)
    {
        if (!ar[i])
        {
            ar[i] = 1;
            dfs(i + 1, cnt + 1);
            ar[i] = 0;
        }
    }
}
int main()
{
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = -1;
        }
    }
    dfs(0, 0);
    cout << ans;
}