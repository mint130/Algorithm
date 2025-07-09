#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, X;
int dist[10001]; // dist 저장
int dist2[10001];
vector<pair<int, int>> v[10001]; // {거리, 도착점}
vector<pair<int, int>> rev[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq2;
int main()
{
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++)
    {
        int st, en, t;
        cin >> st >> en >> t;
        v[st].push_back({t, en});
        rev[en].push_back({t, st});
    }
    // x에서 1~N까지의 최단거리
    fill(dist, dist + N + 1, 987654321);
    // 1~N에서 x까지 최단거리
    fill(dist2, dist2 + N + 1, 987654321);
    dist[X] = 0;
    dist2[X] = 0;
    pq.push({0, X});
    pq2.push({0, X});
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for (auto nxt : v[cur])
        {
            if (nxt.first + d < dist[nxt.second])
            {
                dist[nxt.second] = nxt.first + d;
                pq.push({dist[nxt.second], nxt.second});
            }
        }
    }
    while (!pq2.empty())
    {
        int cur = pq2.top().second;
        int d = pq2.top().first;
        pq2.pop();
        for (auto nxt : rev[cur])
        {
            if (nxt.first + d < dist2[nxt.second])
            {
                dist2[nxt.second] = nxt.first + d;
                pq2.push({dist2[nxt.second], nxt.second});
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == 987654321 || dist2[i] == 987654321)
            continue;
        ans.push_back(dist[i] + dist2[i]);
    }
    sort(ans.begin(), ans.end());
    cout << ans[ans.size() - 1];
}