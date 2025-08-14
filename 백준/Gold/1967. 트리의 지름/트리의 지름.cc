#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n;
vector<pair<int, int>> v[10001]; // v[i]의 자식들이 저장 {가중치, 목적지}
int parent[10001];               // i의 부모 노드번호 저장
int dist[10001];                 // i부터 다른 노드까지의 거리
int ans;
void dfs(int cur)
{
    for (auto nxt : v[cur])
    {
        if (dist[nxt.second] != -1)
            continue;
        dist[nxt.second] = dist[cur] + nxt.first;
        ans = max(ans, dist[nxt.second]);
        dfs(nxt.second);
    }
}
int main()
{
    cin >> n;
    // 루트는 항상 1
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, e;
        cin >> a >> b >> e;
        v[a].push_back({e, b});
        v[b].push_back({e, a});
    }
    for (int i = 1; i <= n; i++)
    {
        fill(dist, dist + n + 1, -1);
        dist[i] = 0;
        dfs(i);
    }
    cout << ans;
}