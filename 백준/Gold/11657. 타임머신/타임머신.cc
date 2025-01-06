#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
long long dist[501]; // 출발점에서 도착점까지의 이동 시간
vector<pair<int, pair<int, int>>> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 987654321; // 초기화
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}}); // cost, 시작, 끝
    }
    dist[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        // i번째 정점에서 갈 수 있는 edge 모두 탐색
        for (auto edge : v)
        {
            int cost = edge.first;
            int st = edge.second.first;
            int en = edge.second.second;

            if (dist[st] == 987654321)
                continue;
            if (dist[en] > dist[st] + cost)
            {
                dist[en] = dist[st] + cost;
            }
        }
    }
    // 음수 사이클 존재: -1 출력
    for (auto edge : v)
    {
        int cost = edge.first;
        int st = edge.second.first;
        int en = edge.second.second;
        if (dist[st] == 987654321)
            continue;
        if (dist[en] > dist[st] + cost)
        {
            cout << -1;
            return 0;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (dist[i] == 987654321)
            dist[i] = -1;
        cout << dist[i] << "\n";
    }
}