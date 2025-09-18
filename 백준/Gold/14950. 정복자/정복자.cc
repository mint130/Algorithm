#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m, t;
bool visited[10001];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
vector<pair<int, int>> v[10001]; // cost node

int main()
{
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    pq.push({0, 1});
    int cnt = 0;
    long long ans = 0;
    while (!pq.empty())
    {
        long long cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (visited[cur])
            continue;
        visited[cur] = 1;
        if (cnt == 0)
            ans += cost;
        else
            ans += cost + ((cnt - 1) * t);
        cnt++;
        for (auto nxt : v[cur])
        {
            if (!visited[nxt.second])
            {
                pq.push({nxt.first, nxt.second});
            }
        }
    }
    cout << ans;
}