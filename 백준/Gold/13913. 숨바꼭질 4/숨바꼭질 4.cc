#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int dist[100001];

int main()
{
    cin >> n >> k;
    fill(dist, dist + 100001, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == k)
        {
            cout << dist[cur] << "\n";
            // for (int i = 1; i <= 100000; i++)
            // {
            //     if (dist[i] != -1)
            //     {
            //         cout << i << " " << dist[i] << endl;
            //     }
            // }
            break;
        }
        if (cur - 1 >= 0 && dist[cur - 1] == -1)
        {
            //-1
            dist[cur - 1] = dist[cur] + 1;
            q.push(cur - 1);
        }
        if (cur + 1 <= 100000 && dist[cur + 1] == -1)
        {
            //+1
            dist[cur + 1] = dist[cur] + 1;
            q.push(cur + 1);
        }
        if (cur * 2 <= 100000 && dist[cur * 2] == -1)
        {
            // 2배
            dist[cur * 2] = dist[cur] + 1;
            q.push(cur * 2);
        }
    }
    int cnt = dist[k]; // 도달하기 위한 시각

    queue<int> q2;
    q2.push(k);
    vector<int> v;
    while (!q2.empty())
    {
        int cur = q2.front();
        q2.pop();
        v.push_back(cur);
        if (cnt == 0)
        {
            reverse(v.begin(), v.end());
            for (auto i : v)
            {
                cout << i << " ";
            }
            return 0;
        }
        if (cur % 2 == 0 && dist[cur / 2] == cnt - 1)
        {
            q2.push(cur / 2);
            cnt = cnt - 1;
        }
        else if (cur + 1 <= 100000 && dist[cur + 1] == cnt - 1)
        {
            q2.push(cur + 1);
            cnt = cnt - 1;
        }
        else if (cur - 1 >= 0 && dist[cur - 1] == cnt - 1)
        {
            q2.push(cur - 1);
            cnt = cnt - 1;
        }
    }
}