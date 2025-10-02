#include <iostream>
#include <algorithm>
using namespace std;
string s, t, r;
int dp[101][101][101];
int main()
{
    cin >> s >> t >> r;
    s = '0' + s;
    t = '0' + t;
    r = '0' + r;

    for (int i = 1; i < s.length(); i++)
    {
        for (int j = 1; j < t.length(); j++)
        {
            for (int k = 1; k < r.length(); k++)
            {
                if (s[i] == t[j] && t[j] == r[k])
                {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else
                {
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }
    }

    cout << dp[s.length() - 1][t.length() - 1][r.length() - 1];
}
