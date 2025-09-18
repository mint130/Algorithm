#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
long long sum;
int n, m;
vector<pair<int, int>> v[100001]; // cost, node
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
bool visited[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        sum += c; // 모든 비용 더함
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    pq.push({0, 1}); // cost, node
    long long ans = 0;
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
                pq.push({nxt.first, nxt.second});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            // 방문하지 않은 점이 있음 -> 모든 그래프가 연결되지 않음
            cout << -1;
            return 0;
        }
    }
    cout << sum - ans;
}