#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<pair<int, int>> adj[100001]; // 가중치, 목적지
bool visited[100001];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; // 가중치, 목적지
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    pq.push({0, 1});
    int cnt = 0;
    long long sum = 0;
    long long edge = 0;
    while (!pq.empty())
    {
        int cur = pq.top().second;
        long long cost = pq.top().first;
        pq.pop();
        if (visited[cur])
            continue;
        visited[cur] = 1;
        cnt++;
        sum += cost;
        edge = max(edge, cost); // 가장 긴 간선찾음
        for (auto nxt : adj[cur])
        {
            if (visited[nxt.second])
                continue;
            pq.push({nxt.first, nxt.second}); // 가중치, 목적지
        }
    }
    cout << sum - edge << endl;
}