#include <iostream>
#include <algorithm>
using namespace std;
long long dp[41], a[41], b[41];
int t, n;
int main()
{
    cin >> t;
    dp[0] = 0;
    dp[1] = 1;
    a[0] = 1;
    a[1] = 0; // 0이 쓰는 횟수
    b[0] = 0;
    b[1] = 1; // 1이 쓰는 횟수
    for (int i = 2; i <= 40; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        a[i] = a[i - 1] + a[i - 2];
        b[i] = b[i - 1] + b[i - 2];
    }

    for (int tc = 0; tc < t; tc++)
    {
        cin >> n;
        cout << a[n] << " " << b[n] << "\n";
    }
}