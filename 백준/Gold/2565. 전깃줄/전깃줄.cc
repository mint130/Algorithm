#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<pair<int, int>> v;
int dp[101]; // i까지 가장 긴 증가하는 부분 수열 길이
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    // vector안의 pair second 정렬하여 그 중 가장 긴 증가하는 부분 수열
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[i].second > v[j].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i], ans); // 가장 증가하는 긴 부분수열 중 최장 길이
    }
    cout << n - ans;
}