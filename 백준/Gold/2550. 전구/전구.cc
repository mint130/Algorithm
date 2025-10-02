#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a[10001], b[10001], used[10001];
int dp[10001], parent[10001];
vector<pair<pair<int, int>, int>> v;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (used[a[i]])
                continue;
            if (a[i] == b[j])
            {
                v.push_back({{i, j}, a[i]});
                used[a[i]] = 1;
            }
        }
    }

    sort(v.begin(), v.end());

    int last = 0; // LIS의 마지막 인덱스
    int len = 0;  // LIS의 길이
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        parent[i] = -1;
        for (int j = n - 1; j >= 0; j--)
        {
            if (v[i].first.second > v[j].first.second)
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j; // 역추적 위해 어디서 왔는지 저장
                }
            }
        }
        if (dp[i] > len)
        {
            len = dp[i];
            last = i;
        }
    }
    cout << len << "\n";

    vector<int> ans;
    for (int i = last; i != -1; i = parent[i])
    {
        ans.push_back(v[i].second);
    }
    reverse(ans.begin(), ans.end());
    sort(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";
}