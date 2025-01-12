#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1001];
int dp[1001]; // 가장 긴 증가하는 부분 수열의 길이

int n, ans;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ans = 1; 
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1; // 자기 자신
        for (int j = n - 1; j >= 0; j--)
        {
            // i-1에서 0까지 순회하며 arr[i]보다 작은 값이 있으면 증가하는 부분 수열 갱신
            if (arr[j] < arr[i])
            {
                // 증가하는 부분 수열이 될 수 있음
                dp[i] = max(dp[j] + 1, dp[i]);
            }
            // dp[i]는 i에서 가장 긴 증가하는 부분 수열의 길이가 됨, ans 갱신
            ans = max(dp[i], ans);
        }
    }

    cout << ans << "\n";
    vector<int> v;

    for (int i = n - 1; i >= 0; i--)
    {
        if (dp[i] == ans)
        {
            v.push_back(arr[i]);
            ans--;
        }
    }
    reverse(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << " ";
    }
}