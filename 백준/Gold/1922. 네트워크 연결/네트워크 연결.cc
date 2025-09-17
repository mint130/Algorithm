#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 비용, 정점
bool visited[1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        // a, b, 비용 c
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    pq.push({0, 1});
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;

        pq.pop();
        if (visited[cur])
            continue;
        visited[cur] = 1;
        ans += cost;
        for (auto nxt : v[cur])
        {
            if (!visited[nxt.second])
            {
                pq.push({nxt.first, nxt.second}); // 비용, 다음 정점
            }
        }
    }
    cout << ans;
}