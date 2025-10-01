#include <iostream>
#include <algorithm>
using namespace std;
int dp[4001][4001]; // s의 i, t의 j까지 왔을 때 최장 공통 부분 문자열의 길이
int main()
{
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < t.length(); j++)
        {
            if (i == 0 || j == 0)
            {
                if (s[i] == t[j])
                {
                    dp[i][j] = 1;
                }
            }
            else
            {
                if (s[i] == t[j])
                {
                    if (dp[i - 1][j - 1] == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < t.length(); j++)
        {
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans;
}