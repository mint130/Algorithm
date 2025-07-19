#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string s1, s2;
int dp[1001][1001]; // s1의 i, s2의 j에 올 때까지 최장 공통 부분 수열 길이
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

    cout << dp[s1.length() - 1][s2.length() - 1];
}