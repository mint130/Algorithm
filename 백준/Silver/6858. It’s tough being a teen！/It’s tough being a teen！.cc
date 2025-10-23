#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[30];
vector<int> ans;
priority_queue<int, vector<int>, greater<>> q;
int in[30];
int m = 7;
int main()
{
    v[1].push_back(7);
    in[7]++;
    v[1].push_back(4);
    in[4]++;
    v[2].push_back(1);
    in[1]++;
    v[3].push_back(4);
    in[4]++;
    v[3].push_back(5);
    in[5]++;

    while (1)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        v[a].push_back(b);
        in[b]++;
        m = max({m, a, b});
    }

    for (int i = 1; i <= m; i++)
    {
        sort(v[i].begin(), v[i].end());
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    bool flag = 0;
    while (!q.empty())
    {
        int cur = q.top();
        q.pop();
        ans.push_back(cur);

        for (auto nxt : v[cur])
        {
            in[nxt]--;
            if (in[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }
    if (ans.size() != m)
        cout << "Cannot complete these tasks. Going to bed.";
    else
    {
        for (auto i : ans)
        {
            cout << i << " ";
        }
    }
}