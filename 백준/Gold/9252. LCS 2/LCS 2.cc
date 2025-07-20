#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string s1, s2;
int dp[1001][1001];
int main()
{
    cin >> s1 >> s2;
    s1 = "0" + s1;
    s2 = "0" + s2;
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[s1.length() - 1][s2.length() - 1] << "\n";
    string ans = "";
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    while (i > 0 && j > 0)
    {
        if (s1[i] == s2[j])
        {
            ans += s1[i];
            if (i > 0)
                i--;
            if (j > 0)
                j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}