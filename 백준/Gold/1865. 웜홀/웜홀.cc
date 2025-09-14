#include <iostream>
#include <vector>
using namespace std;
int T, n, m, w;
vector<pair<int, pair<int, int>>> v; //  비용, 시작, 끝
int dist[501];
bool bell_ford(int num)
{
    fill(dist, dist + n + 1, 987654321);
    dist[num] = 0;
    // n번 반복
    for (int i = 1; i <= n; i++)
    {
        for (auto edge : v)
        {
            int cost = edge.first;
            int st = edge.second.first;
            int en = edge.second.second;
            if (dist[en] > dist[st] + cost)
            {
                dist[en] = dist[st] + cost;
                // n번째에도 감소 된다면 음수 가중치 있는 것
                if (i == n)
                    return true;
            }
        }
    }
    return false;
    /*
    for (auto edge : v)
    {
        int cost = edge.first;
        int st = edge.second.first;
        int en = edge.second.second;
        if (dist[en] > dist[st] + cost)
        {
            // 음수 사이클 존재
            return true;
        }
    }
    return false;
    */
}
int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> n >> m >> w;
        // n 지점 수 m 도로 수 w 웜홀 수
        v.clear();
        for (int i = 0; i < m; i++)
        {
            int s, e, t;
            // 번호 시간
            cin >> s >> e >> t;
            v.push_back({t, {s, e}});
            v.push_back({t, {e, s}});
        }
        for (int i = 0; i < w; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            v.push_back({-t, {s, e}});
        }
        // 모든 노드가 0과 연결되게
        for (int i = 1; i <= n; i++)
        {
            v.push_back({0, {i, 0}});
        }
        if (bell_ford(0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}