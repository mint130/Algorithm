#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int in[1001];
vector<int> v[1001];
queue<int> q;
int ans[1001];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        in[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        // 진입 차수가 0인 정점 큐에 추가
        if (in[i] == 0)
        {
            q.push(i);
            ans[i] = 1;
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto nxt : v[cur])
        {
            in[nxt]--; // 진입차수 줄임
            ans[nxt] = ans[cur] + 1;
            if (in[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}