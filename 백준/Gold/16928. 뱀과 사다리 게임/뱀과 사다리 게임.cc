#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n, m;
int dist[101];
map<int, int> l;
map<int, int> s;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        l[a] = b;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        s[a] = b;
    }
    fill(dist, dist + 101, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == 100)
        {
            cout << dist[cur];
            return 0;
        }

        for (int i = 1; i <= 6; i++)
        {
            int nxt = cur + i;
            if (nxt > 100)
                continue;
            // 사다리거나 뱀인지 확인
            if (l[nxt] != 0)
            {
                nxt = l[nxt];
            }
            else if (s[nxt] != 0)
            {
                nxt = s[nxt];
            }
            if (dist[nxt] != -1)
                continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
}