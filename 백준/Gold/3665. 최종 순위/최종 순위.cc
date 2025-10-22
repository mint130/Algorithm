#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#include <cstring>
#include <stack>
using namespace std;
int n, m, T;

int in[501];
int adj[501][501]; // adj[a][b] b가 더 낮은 순위

int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> n;

        fill(in, in + n + 1, 0);
        memset(adj, 0, sizeof(adj));
        queue<int> q;
        vector<int> tmp;
        for (int i = 1; i <= n; i++)
        {
            int num;
            cin >> num;
            tmp.push_back(num);
        }
        for (int i = 0; i < tmp.size(); i++)
        {
            for (int j = i + 1; j < tmp.size(); j++)
            {
                adj[tmp[i]][tmp[j]] = 1;
                in[tmp[j]]++;
            }
        }

        cin >> m;

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if (adj[b][a])
            {
                // 작년에는 a의 등수가 더 낮았음(큼) -> 올해는 a가 더 높은 등수(작음)
                in[b]++;
                adj[a][b] = 1;
                adj[b][a] = 0;
                in[a]--;
            }
            else
            {
                // 작년에는 b의 등수가 더 낮았음(큼) -> 올해는 b가 더 높은 등수(작음)
                in[a]++;
                adj[b][a] = 1;
                adj[a][b] = 0;
                in[b]--;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            // 제일 처음 들어간게 1등(순위가 높음)
            if (in[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        bool flag = 0;
        while (!q.empty())
        {
            if (q.size() >= 2)
            {
                flag = 1;
                break;
            }
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for (int i = 1; i <= n; i++)
            {
                if (adj[cur][i])
                {
                    in[i]--;
                    if (in[i] == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }
        if (flag)
        {
            // 알 수 없음
            cout << "?\n";
            continue;
        }
        if (ans.size() != n)
        {
            cout << "IMPOSSIBLE" << "\n";
        }
        else
        {
            for (auto i : ans)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
}